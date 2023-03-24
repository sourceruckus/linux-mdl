/* SPDX-License-Identifier: GPL-2.0-only */
#ifndef GENL_MAGIC_FUNC_H
#define GENL_MAGIC_FUNC_H

#include <linux/genl_magic_struct.h>

/*
 * Magic: declare tla policy						{{{1
 * Magic: declare nested policies
 *									{{{2
 */
#undef GENL_mc_group
#define GENL_mc_group(group)

#undef GENL_notification
#define GENL_notification(op_name, op_num, mcast_group, tla_list)

#undef GENL_op
#define GENL_op(op_name, op_num, handler, tla_list)

#undef GENL_struct
#define GENL_struct(tag_name, tag_number, s_name, s_fields)		\
	[tag_name] = { .type = NLA_NESTED },

static struct nla_policy CONCAT_(GENL_MAGIC_FAMILY, _tla_nl_policy)[]	\
		__attribute__((unused)) = {
#include GENL_MAGIC_INCLUDE_FILE
};

#undef GENL_struct
#define GENL_struct(tag_name, tag_number, s_name, s_fields)		\
static struct nla_policy s_name ## _nl_policy[] __read_mostly =		\
{ s_fields };

#undef __field
#define __field(attr_nr, attr_flag, name, nla_type, _type, __get,	\
		 __put, __is_signed)					\
	[attr_nr] = { .type = nla_type },

#undef __array
#define __array(attr_nr, attr_flag, name, nla_type, _type, maxlen,	\
		__get, __put, __is_signed)				\
	[attr_nr] = { .type = nla_type,					\
		      .len = maxlen - (nla_type == NLA_NUL_STRING) },

#include GENL_MAGIC_INCLUDE_FILE

#ifndef __KERNEL__
#ifndef pr_info
#define pr_info(args...)	fprintf(stderr, args);
#endif
/* genl_magic_func.h generates *_from_attrs() helper functions
 * that now allocate/free the nested attribute tables.
 * Map the kernel API to what we use in userland. */
#define kcalloc(nmem, size, gfp) calloc((nmem), (size))
#define kfree(p) free(p)
#endif

#ifdef GENL_MAGIC_DEBUG
static void dprint_field(const char *dir, int nla_type,
		const char *name, void *valp)
{
	__u64 val = valp ? *(__u32 *)valp : 1;
	switch (nla_type) {
	case NLA_U8:  val = (__u8)val;
	case NLA_U16: val = (__u16)val;
	case NLA_U32: val = (__u32)val;
		pr_info("%s attr %s: %d 0x%08x\n", dir,
			name, (int)val, (unsigned)val);
		break;
	case NLA_U64:
		val = *(__u64*)valp;
		pr_info("%s attr %s: %lld 0x%08llx\n", dir,
			name, (long long)val, (unsigned long long)val);
		break;
	case NLA_FLAG:
		if (val)
			pr_info("%s attr %s: set\n", dir, name);
		break;
	}
}

static void dprint_array(const char *dir, int nla_type,
		const char *name, const char *val, unsigned len)
{
	switch (nla_type) {
	case NLA_NUL_STRING:
		if (len && val[len-1] == '\0')
			len--;
		pr_info("%s attr %s: [len:%u] '%s'\n", dir, name, len, val);
		break;
	default:
		/* we can always show 4 byte,
		 * thats what nlattr are aligned to. */
		pr_info("%s attr %s: [len:%u] %02x%02x%02x%02x ...\n",
			dir, name, len, val[0], val[1], val[2], val[3]);
	}
}

#define DPRINT_TLA(a, op, b) pr_info("%s %s %s\n", a, op, b);

/* Name is a member field name of the struct s.
 * If s is NULL (only parsing, no copy requested in *_from_attrs()),
 * nla is supposed to point to the attribute containing the information
 * corresponding to that struct member. */
#define DPRINT_FIELD(dir, nla_type, name, s, nla)			\
	do {								\
		if (s)							\
			dprint_field(dir, nla_type, #name, &s->name);	\
		else if (nla)						\
			dprint_field(dir, nla_type, #name,		\
				(nla_type == NLA_FLAG) ? NULL		\
						: nla_data(nla));	\
	} while (0)

#define	DPRINT_ARRAY(dir, nla_type, name, s, nla)			\
	do {								\
		if (s)							\
			dprint_array(dir, nla_type, #name,		\
					s->name, s->name ## _len);	\
		else if (nla)						\
			dprint_array(dir, nla_type, #name,		\
					nla_data(nla), nla_len(nla));	\
	} while (0)
#else
#define DPRINT_TLA(a, op, b) do {} while (0)
#define DPRINT_FIELD(dir, nla_type, name, s, nla) do {} while (0)
#define	DPRINT_ARRAY(dir, nla_type, name, s, nla) do {} while (0)
#endif

/*
 * Magic: provide conversion functions					{{{1
 * populate struct from attribute table:
 *									{{{2
 */

#undef GENL_struct
#define GENL_struct(tag_name, tag_number, s_name, s_fields)		\
static int __ ## s_name ## _from_attrs(struct s_name *s,		\
		struct nlattr ***ret_nested_attribute_table,		\
		struct genl_info *info, bool exclude_invariants)	\
{									\
	const int maxtype = ARRAY_SIZE(s_name ## _nl_policy)-1;		\
	struct nlattr *tla = info->attrs[tag_number];			\
	struct nlattr **ntb;						\
	struct nlattr *nla;						\
	int err = 0;							\
	if (ret_nested_attribute_table)					\
		*ret_nested_attribute_table = NULL;			\
	if (!tla)							\
		return -ENOMSG;						\
	ntb = kcalloc(ARRAY_SIZE(s_name ## _nl_policy), sizeof(*ntb), GFP_KERNEL); \
	if (!ntb)							\
		return -ENOMEM;						\
	DPRINT_TLA(#s_name, "<=-", #tag_name);				\
	err = drbd_nla_parse_nested(ntb, maxtype, tla, s_name ## _nl_policy);	\
	if (err)							\
		goto out;						\
									\
	s_fields							\
 out:									\
	if (!err && ret_nested_attribute_table)				\
		*ret_nested_attribute_table = ntb;			\
	else								\
		kfree(ntb);						\
	return err;							\
}					__attribute__((unused))		\
static int s_name ## _from_attrs(struct s_name *s,			\
						struct genl_info *info)	\
{									\
	return __ ## s_name ## _from_attrs(s, NULL, info, false);	\
}					__attribute__((unused))		\
static int s_name ## _ntb_from_attrs(					\
			struct nlattr ***ret_nested_attribute_table,	\
						struct genl_info *info)	\
{									\
	return __ ## s_name ## _from_attrs(NULL,			\
			ret_nested_attribute_table, info, false);	\
}					__attribute__((unused))		\
static int s_name ## _from_attrs_for_change(struct s_name *s,		\
						struct genl_info *info)	\
{									\
	return __ ## s_name ## _from_attrs(s, NULL, info, true);	\
}					__attribute__((unused))		\

#define __assign(attr_nr, attr_flag, name, nla_type, type, assignment...)	\
		nla = ntb[attr_nr];						\
		if (nla) {						\
			if (exclude_invariants && !!((attr_flag) & DRBD_F_INVARIANT)) {		\
				pr_info("<< must not change invariant attr: %s\n", #name);	\
				err = -EEXIST;				\
				goto out;				\
			}						\
			assignment;					\
		} else if (exclude_invariants && !!((attr_flag) & DRBD_F_INVARIANT)) {		\
			/* attribute missing from payload, */		\
			/* which was expected */			\
		} else if ((attr_flag) & DRBD_F_REQUIRED) {		\
			pr_info("<< missing attr: %s\n", #name);	\
			err = -ENOMSG;					\
			goto out;					\
		}

#undef __field
#define __field(attr_nr, attr_flag, name, nla_type, type, __get, __put,	\
		__is_signed)						\
	__assign(attr_nr, attr_flag, name, nla_type, type,		\
			if (s)						\
				s->name = __get(nla);			\
			DPRINT_FIELD("<<", nla_type, name, s, nla))

/* validate_nla() already checked nla_len <= maxlen appropriately. */
#undef __array
#define __array(attr_nr, attr_flag, name, nla_type, type, maxlen,	\
		__get, __put, __is_signed)				\
	__assign(attr_nr, attr_flag, name, nla_type, type,		\
			if (s)						\
				s->name ## _len =			\
					__get(s->name, nla, maxlen);	\
			DPRINT_ARRAY("<<", nla_type, name, s, nla))

#include GENL_MAGIC_INCLUDE_FILE

#undef GENL_struct
#define GENL_struct(tag_name, tag_number, s_name, s_fields)

/*
 * Magic: define op number to op name mapping				{{{1
 *									{{{2
 */
static const char *CONCAT_(GENL_MAGIC_FAMILY, _genl_cmd_to_str)(__u8 cmd)
__attribute__ ((unused));
static const char *CONCAT_(GENL_MAGIC_FAMILY, _genl_cmd_to_str)(__u8 cmd)
{
	switch (cmd) {
#undef GENL_op
#define GENL_op(op_name, op_num, handler, tla_list)		\
	case op_num: return #op_name;
#include GENL_MAGIC_INCLUDE_FILE
	default:
		     return "unknown";
	}
}

#ifdef __KERNEL__
#include <linux/stringify.h>
/*
 * Magic: define genl_ops						{{{1
 *									{{{2
 */

#undef GENL_op
#define GENL_op(op_name, op_num, handler, tla_list)		\
{								\
	handler							\
	.cmd = op_name,						\
	.policy	= CONCAT_(GENL_MAGIC_FAMILY, _tla_nl_policy),	\
},

#define ZZZ_genl_ops		CONCAT_(GENL_MAGIC_FAMILY, _genl_ops)
static struct genl_ops ZZZ_genl_ops[] __read_mostly = {
#include GENL_MAGIC_INCLUDE_FILE
};

#undef GENL_op
#define GENL_op(op_name, op_num, handler, tla_list)

/*
 * Define the genl_family, multicast groups,				{{{1
 * and provide register/unregister functions.
 *									{{{2
 */
#define ZZZ_genl_family		CONCAT_(GENL_MAGIC_FAMILY, _genl_family)
static struct genl_family ZZZ_genl_family;

/*
 * Magic: define multicast groups
 * Magic: define multicast group registration helper
 */

/* COMPAT
 * See linux 3.13,
 * genetlink: make multicast groups const, prevent abuse
 * genetlink: pass family to functions using groups
 * genetlink: only pass array to genl_register_family_with_ops()
 * which are commits c53ed742..2a94fe48
 *
 * v4.10, 489111e5 genetlink: statically initialize families
 *   and previous commit drop GENL_ID_GENERATE and register helper functions.
 */
#if defined(genl_register_family_with_ops_groups) || !defined(GENL_ID_GENERATE)
#include <linux/genl_magic_func-genl_register_family_with_ops_groups.h>
#else
#include <linux/genl_magic_func-genl_register_mc_group.h>
#endif

static struct genl_family ZZZ_genl_family __read_mostly = {
	/* .id = GENL_ID_GENERATE, which exists no longer, and was 0 anyways */
	.name = __stringify(GENL_MAGIC_FAMILY),
	.version = GENL_MAGIC_VERSION,
#ifdef GENL_MAGIC_FAMILY_HDRSZ
	.hdrsize = NLA_ALIGN(GENL_MAGIC_FAMILY_HDRSZ),
#endif
	.maxattr = ARRAY_SIZE(CONCAT_(GENL_MAGIC_FAMILY, _tla_nl_policy))-1,

#ifndef GENL_ID_GENERATE
	.ops = ZZZ_genl_ops,
	.n_ops = ARRAY_SIZE(ZZZ_genl_ops),
	.mcgrps = ZZZ_genl_mcgrps,
	.n_mcgrps = ARRAY_SIZE(ZZZ_genl_mcgrps),
	.module = THIS_MODULE,
#endif
	.netnsok = true,
	.parallel_ops = true,
};

/*
 * Magic: provide conversion functions					{{{1
 * populate skb from struct.
 *									{{{2
 */

#undef GENL_op
#define GENL_op(op_name, op_num, handler, tla_list)

#undef GENL_struct
#define GENL_struct(tag_name, tag_number, s_name, s_fields)		\
static int s_name ## _to_skb(struct sk_buff *skb, struct s_name *s,	\
		const bool exclude_sensitive)				\
{									\
	struct nlattr *tla = nla_nest_start(skb, tag_number);		\
	if (!tla)							\
		goto nla_put_failure;					\
	DPRINT_TLA(#s_name, "-=>", #tag_name);				\
	s_fields							\
	nla_nest_end(skb, tla);						\
	return 0;							\
									\
nla_put_failure:							\
	if (tla)							\
		nla_nest_cancel(skb, tla);				\
        return -EMSGSIZE;						\
}									\
static inline int s_name ## _to_priv_skb(struct sk_buff *skb,		\
		struct s_name *s)					\
{									\
	return s_name ## _to_skb(skb, s, 0);				\
}									\
static inline int s_name ## _to_unpriv_skb(struct sk_buff *skb,		\
		struct s_name *s)					\
{									\
	return s_name ## _to_skb(skb, s, 1);				\
}


#undef __field
#define __field(attr_nr, attr_flag, name, nla_type, type, __get, __put,	\
		__is_signed)						\
	if (!exclude_sensitive || !((attr_flag) & DRBD_F_SENSITIVE)) {	\
		DPRINT_FIELD(">>", nla_type, name, s, NULL);		\
		if (__put(skb, attr_nr, s->name))			\
			goto nla_put_failure;				\
	}

#undef __array
#define __array(attr_nr, attr_flag, name, nla_type, type, maxlen,	\
		__get, __put, __is_signed)				\
	if (!exclude_sensitive || !((attr_flag) & DRBD_F_SENSITIVE)) {	\
		DPRINT_ARRAY(">>",nla_type, name, s, NULL);		\
		if (__put(skb, attr_nr, min_t(int, maxlen,		\
			s->name ## _len + (nla_type == NLA_NUL_STRING)),\
						s->name))		\
			goto nla_put_failure;				\
	}

#include GENL_MAGIC_INCLUDE_FILE


/* Functions for initializing structs to default values.  */

#undef __field
#define __field(attr_nr, attr_flag, name, nla_type, type, __get, __put,	\
		__is_signed)
#undef __array
#define __array(attr_nr, attr_flag, name, nla_type, type, maxlen,	\
		__get, __put, __is_signed)
#undef __u32_field_def
#define __u32_field_def(attr_nr, attr_flag, name, default)		\
	x->name = default;
#undef __s32_field_def
#define __s32_field_def(attr_nr, attr_flag, name, default)		\
	x->name = default;
#undef __flg_field_def
#define __flg_field_def(attr_nr, attr_flag, name, default)		\
	x->name = default;
#undef __str_field_def
#define __str_field_def(attr_nr, attr_flag, name, maxlen)		\
	memset(x->name, 0, sizeof(x->name));				\
	x->name ## _len = 0;
#undef GENL_struct
#define GENL_struct(tag_name, tag_number, s_name, s_fields)		\
static void set_ ## s_name ## _defaults(struct s_name *x) __attribute__((unused)); \
static void set_ ## s_name ## _defaults(struct s_name *x) {	\
s_fields								\
}

#include GENL_MAGIC_INCLUDE_FILE

#endif /* __KERNEL__ */

/* }}}1 */
#endif /* GENL_MAGIC_FUNC_H */
/* vim: set foldmethod=marker foldlevel=1 nofoldenable : */
