/* zfs_config.h.  Generated from zfs_config.h.in by configure.  */
/* zfs_config.h.in.  Generated from configure.ac by autoheader.  */

/* Define to 1 if translation of program messages to the user's native
   language is requested. */
#define ENABLE_NLS 1

/* bio_end_io_t wants 1 arg */
#define HAVE_1ARG_BIO_END_IO_T 1

/* lookup_bdev() wants 1 arg */
#define HAVE_1ARG_LOOKUP_BDEV 1

/* submit_bio() wants 1 arg */
#define HAVE_1ARG_SUBMIT_BIO 1

/* bdi_setup_and_register() wants 2 args */
/* #undef HAVE_2ARGS_BDI_SETUP_AND_REGISTER */

/* vfs_getattr wants 2 args */
/* #undef HAVE_2ARGS_VFS_GETATTR */

/* zlib_deflate_workspacesize() wants 2 args */
#define HAVE_2ARGS_ZLIB_DEFLATE_WORKSPACESIZE 1

/* bdi_setup_and_register() wants 3 args */
/* #undef HAVE_3ARGS_BDI_SETUP_AND_REGISTER */

/* vfs_getattr wants 3 args */
/* #undef HAVE_3ARGS_VFS_GETATTR */

/* vfs_getattr wants 4 args */
#define HAVE_4ARGS_VFS_GETATTR 1

/* kernel has access_ok with 'type' parameter */
/* #undef HAVE_ACCESS_OK_TYPE */

/* posix_acl has refcount_t */
#define HAVE_ACL_REFCOUNT 1

/* Define if host toolchain supports AES */
#define HAVE_AES 1

/* Define if host toolchain supports AVX */
#define HAVE_AVX 1

/* Define if host toolchain supports AVX2 */
#define HAVE_AVX2 1

/* Define if host toolchain supports AVX512BW */
#define HAVE_AVX512BW 1

/* Define if host toolchain supports AVX512CD */
#define HAVE_AVX512CD 1

/* Define if host toolchain supports AVX512DQ */
#define HAVE_AVX512DQ 1

/* Define if host toolchain supports AVX512ER */
#define HAVE_AVX512ER 1

/* Define if host toolchain supports AVX512F */
#define HAVE_AVX512F 1

/* Define if host toolchain supports AVX512IFMA */
#define HAVE_AVX512IFMA 1

/* Define if host toolchain supports AVX512PF */
#define HAVE_AVX512PF 1

/* Define if host toolchain supports AVX512VBMI */
#define HAVE_AVX512VBMI 1

/* Define if host toolchain supports AVX512VL */
#define HAVE_AVX512VL 1

/* bdev_check_media_change() exists */
#define HAVE_BDEV_CHECK_MEDIA_CHANGE 1

/* block_device_operations->submit_bio() returns void */
/* #undef HAVE_BDEV_SUBMIT_BIO_RETURNS_VOID */

/* bdev_whole() is available */
/* #undef HAVE_BDEV_WHOLE */

/* bio->bi_bdev->bd_disk exists */
/* #undef HAVE_BIO_BDEV_DISK */

/* bio->bi_opf is defined */
#define HAVE_BIO_BI_OPF 1

/* bio->bi_status exists */
#define HAVE_BIO_BI_STATUS 1

/* bio has bi_iter */
#define HAVE_BIO_BVEC_ITER 1

/* bio_*_io_acct() available */
/* #undef HAVE_BIO_IO_ACCT */

/* bio_max_segs() is implemented */
/* #undef HAVE_BIO_MAX_SEGS */

/* bio_set_dev() is available */
#define HAVE_BIO_SET_DEV 1

/* bio_set_dev() GPL-only */
/* #undef HAVE_BIO_SET_DEV_GPL_ONLY */

/* bio_set_dev() is a macro */
#define HAVE_BIO_SET_DEV_MACRO 1

/* bio_set_op_attrs is available */
#define HAVE_BIO_SET_OP_ATTRS 1

/* blkdev_get_by_path() handles ERESTARTSYS */
#define HAVE_BLKDEV_GET_ERESTARTSYS 1

/* blkdev_reread_part() exists */
/* #undef HAVE_BLKDEV_REREAD_PART */

/* blkg_tryget() is available */
#define HAVE_BLKG_TRYGET 1

/* blkg_tryget() GPL-only */
/* #undef HAVE_BLKG_TRYGET_GPL_ONLY */

/* blk_alloc_disk() exists */
/* #undef HAVE_BLK_ALLOC_DISK */

/* blk_alloc_queue() expects request function */
/* #undef HAVE_BLK_ALLOC_QUEUE_REQUEST_FN */

/* blk_alloc_queue_rh() expects request function */
/* #undef HAVE_BLK_ALLOC_QUEUE_REQUEST_FN_RH */

/* blk queue backing_dev_info is dynamic */
#define HAVE_BLK_QUEUE_BDI_DYNAMIC 1

/* blk_queue_flag_clear() exists */
#define HAVE_BLK_QUEUE_FLAG_CLEAR 1

/* blk_queue_flag_set() exists */
#define HAVE_BLK_QUEUE_FLAG_SET 1

/* blk_queue_flush() is available */
/* #undef HAVE_BLK_QUEUE_FLUSH */

/* blk_queue_flush() is GPL-only */
/* #undef HAVE_BLK_QUEUE_FLUSH_GPL_ONLY */

/* blk_queue_secdiscard() is available */
/* #undef HAVE_BLK_QUEUE_SECDISCARD */

/* blk_queue_secure_erase() is available */
#define HAVE_BLK_QUEUE_SECURE_ERASE 1

/* blk_queue_update_readahead() exists */
#define HAVE_BLK_QUEUE_UPDATE_READAHEAD 1

/* blk_queue_write_cache() exists */
#define HAVE_BLK_QUEUE_WRITE_CACHE 1

/* blk_queue_write_cache() is GPL-only */
/* #undef HAVE_BLK_QUEUE_WRITE_CACHE_GPL_ONLY */

/* Define if revalidate_disk() in block_device_operations */
#define HAVE_BLOCK_DEVICE_OPERATIONS_REVALIDATE_DISK 1

/* Define to 1 if you have the Mac OS X function CFLocaleCopyCurrent in the
   CoreFoundation framework. */
/* #undef HAVE_CFLOCALECOPYCURRENT */

/* Define to 1 if you have the Mac OS X function
   CFLocaleCopyPreferredLanguages in the CoreFoundation framework. */
/* #undef HAVE_CFLOCALECOPYPREFERREDLANGUAGES */

/* Define to 1 if you have the Mac OS X function CFPreferencesCopyAppValue in
   the CoreFoundation framework. */
/* #undef HAVE_CFPREFERENCESCOPYAPPVALUE */

/* check_disk_change() exists */
/* #undef HAVE_CHECK_DISK_CHANGE */

/* clear_inode() is available */
#define HAVE_CLEAR_INODE 1

/* dentry uses const struct dentry_operations */
#define HAVE_CONST_DENTRY_OPERATIONS 1

/* copy_from_iter() is available */
#define HAVE_COPY_FROM_ITER 1

/* copy_to_iter() is available */
#define HAVE_COPY_TO_ITER 1

/* yes */
#define HAVE_CPU_HOTPLUG 1

/* current_time() exists */
#define HAVE_CURRENT_TIME 1

/* Define if the GNU dcgettext() function is already present or preinstalled.
   */
#define HAVE_DCGETTEXT 1

/* DECLARE_EVENT_CLASS() is available */
#define HAVE_DECLARE_EVENT_CLASS 1

/* lookup_bdev() wants dev_t arg */
/* #undef HAVE_DEVT_LOOKUP_BDEV */

/* sops->dirty_inode() wants flags */
#define HAVE_DIRTY_INODE_WITH_FLAGS 1

/* disk_*_io_acct() available */
#define HAVE_DISK_IO_ACCT 1

/* disk_update_readahead() exists */
/* #undef HAVE_DISK_UPDATE_READAHEAD */

/* Define to 1 if you have the <dlfcn.h> header file. */
#define HAVE_DLFCN_H 1

/* d_make_root() is available */
#define HAVE_D_MAKE_ROOT 1

/* d_prune_aliases() is available */
#define HAVE_D_PRUNE_ALIASES 1

/* dops->d_revalidate() operation takes nameidata */
/* #undef HAVE_D_REVALIDATE_NAMEIDATA */

/* eops->encode_fh() wants child and parent inodes */
#define HAVE_ENCODE_FH_WITH_INODE 1

/* sops->evict_inode() exists */
#define HAVE_EVICT_INODE 1

/* fops->aio_fsync() exists */
/* #undef HAVE_FILE_AIO_FSYNC */

/* file_dentry() is available */
#define HAVE_FILE_DENTRY 1

/* file_inode() is available */
#define HAVE_FILE_INODE 1

/* iops->follow_link() cookie */
/* #undef HAVE_FOLLOW_LINK_COOKIE */

/* iops->follow_link() nameidata */
/* #undef HAVE_FOLLOW_LINK_NAMEIDATA */

/* fops->fsync() with range */
#define HAVE_FSYNC_RANGE 1

/* fops->fsync() without dentry */
/* #undef HAVE_FSYNC_WITHOUT_DENTRY */

/* generic_fillattr requires struct user_namespace* */
/* #undef HAVE_GENERIC_FILLATTR_USERNS */

/* generic_*_io_acct() 3 arg available */
/* #undef HAVE_GENERIC_IO_ACCT_3ARG */

/* generic_*_io_acct() 4 arg available */
/* #undef HAVE_GENERIC_IO_ACCT_4ARG */

/* generic_readlink is global */
/* #undef HAVE_GENERIC_READLINK */

/* generic_setxattr() exists */
/* #undef HAVE_GENERIC_SETXATTR */

/* generic_write_checks() takes kiocb */
#define HAVE_GENERIC_WRITE_CHECKS_KIOCB 1

/* Define if the GNU gettext() function is already present or preinstalled. */
#define HAVE_GETTEXT 1

/* iops->get_acl() exists */
#define HAVE_GET_ACL 1

/* iops->get_acl() takes rcu */
/* #undef HAVE_GET_ACL_RCU */

/* iops->get_link() cookie */
/* #undef HAVE_GET_LINK_COOKIE */

/* iops->get_link() delayed */
#define HAVE_GET_LINK_DELAYED 1

/* group_info->gid exists */
#define HAVE_GROUP_INFO_GID 1

/* has_capability() is available */
#define HAVE_HAS_CAPABILITY 1

/* Define if you have the iconv() function and it works. */
/* #undef HAVE_ICONV */

/* Define if compiler supports -Wimplicit-fallthrough */
#define HAVE_IMPLICIT_FALLTHROUGH 1

/* yes */
#define HAVE_INODE_LOCK_SHARED 1

/* inode_owner_or_capable() exists */
#define HAVE_INODE_OWNER_OR_CAPABLE 1

/* inode_owner_or_capable() takes user_ns */
/* #undef HAVE_INODE_OWNER_OR_CAPABLE_IDMAPPED */

/* inode_set_flags() exists */
#define HAVE_INODE_SET_FLAGS 1

/* inode_set_iversion() exists */
#define HAVE_INODE_SET_IVERSION 1

/* inode->i_*time's are timespec64 */
#define HAVE_INODE_TIMESPEC64_TIMES 1

/* timestamp_truncate() exists */
#define HAVE_INODE_TIMESTAMP_TRUNCATE 1

/* Define to 1 if you have the <inttypes.h> header file. */
#define HAVE_INTTYPES_H 1

/* in_compat_syscall() is available */
#define HAVE_IN_COMPAT_SYSCALL 1

/* iops->create() takes struct user_namespace* */
/* #undef HAVE_IOPS_CREATE_USERNS */

/* iops->mkdir() takes struct user_namespace* */
/* #undef HAVE_IOPS_MKDIR_USERNS */

/* iops->mknod() takes struct user_namespace* */
/* #undef HAVE_IOPS_MKNOD_USERNS */

/* iops->rename() takes struct user_namespace* */
/* #undef HAVE_IOPS_RENAME_USERNS */

/* iops->symlink() takes struct user_namespace* */
/* #undef HAVE_IOPS_SYMLINK_USERNS */

/* iov_iter_advance() is available */
#define HAVE_IOV_ITER_ADVANCE 1

/* iov_iter_count() is available */
#define HAVE_IOV_ITER_COUNT 1

/* iov_iter_fault_in_readable() is available */
#define HAVE_IOV_ITER_FAULT_IN_READABLE 1

/* iov_iter_revert() is available */
#define HAVE_IOV_ITER_REVERT 1

/* iov_iter_type() is available */
#define HAVE_IOV_ITER_TYPE 1

/* iov_iter types are available */
#define HAVE_IOV_ITER_TYPES 1

/* yes */
#define HAVE_IO_SCHEDULE_TIMEOUT 1

/* Define to 1 if you have the `issetugid' function. */
/* #undef HAVE_ISSETUGID */

/* kernel has kernel_fpu_* functions */
#define HAVE_KERNEL_FPU 1

/* kernel has asm/fpu/api.h */
#define HAVE_KERNEL_FPU_API_HEADER 1

/* kernel fpu internal */
/* #undef HAVE_KERNEL_FPU_INTERNAL */

/* kernel has asm/fpu/xcr.h */
#define HAVE_KERNEL_FPU_XCR_HEADER 1

/* uncached_acl_sentinel() exists */
#define HAVE_KERNEL_GET_ACL_HANDLE_CACHE 1

/* kernel does stack verification */
#define HAVE_KERNEL_OBJTOOL 1

/* kernel has linux/objtool.h */
#define HAVE_KERNEL_OBJTOOL_HEADER 1

/* kernel_read() take loff_t pointer */
#define HAVE_KERNEL_READ_PPOS 1

/* timer_list.function gets a timer_list */
#define HAVE_KERNEL_TIMER_FUNCTION_TIMER_LIST 1

/* struct timer_list has a flags member */
#define HAVE_KERNEL_TIMER_LIST_FLAGS 1

/* timer_setup() is available */
#define HAVE_KERNEL_TIMER_SETUP 1

/* kernel_write() take loff_t pointer */
#define HAVE_KERNEL_WRITE_PPOS 1

/* kmem_cache_create_usercopy() exists */
#define HAVE_KMEM_CACHE_CREATE_USERCOPY 1

/* kstrtoul() exists */
#define HAVE_KSTRTOUL 1

/* ktime_get_coarse_real_ts64() exists */
#define HAVE_KTIME_GET_COARSE_REAL_TS64 1

/* ktime_get_raw_ts64() exists */
#define HAVE_KTIME_GET_RAW_TS64 1

/* kvmalloc exists */
#define HAVE_KVMALLOC 1

/* Define if you have [aio] */
#define HAVE_LIBAIO 1

/* Define if you have [blkid] */
#define HAVE_LIBBLKID 1

/* Define if you have [crypto] */
#define HAVE_LIBCRYPTO 1

/* Define if you have [tirpc] */
/* #undef HAVE_LIBTIRPC */

/* Define if you have [udev] */
#define HAVE_LIBUDEV 1

/* Define if you have [uuid] */
#define HAVE_LIBUUID 1

/* linux/blk-cgroup.h exists */
#define HAVE_LINUX_BLK_CGROUP_HEADER 1

/* lseek_execute() is available */
/* #undef HAVE_LSEEK_EXECUTE */

/* makedev() is declared in sys/mkdev.h */
/* #undef HAVE_MAKEDEV_IN_MKDEV */

/* makedev() is declared in sys/sysmacros.h */
#define HAVE_MAKEDEV_IN_SYSMACROS 1

/* Noting that make_request_fn() returns blk_qc_t */
/* #undef HAVE_MAKE_REQUEST_FN_RET_QC */

/* Noting that make_request_fn() returns void */
/* #undef HAVE_MAKE_REQUEST_FN_RET_VOID */

/* Define to 1 if you have the <memory.h> header file. */
#define HAVE_MEMORY_H 1

/* iops->mkdir() takes umode_t */
#define HAVE_MKDIR_UMODE_T 1

/* Define to 1 if you have the `mlockall' function. */
#define HAVE_MLOCKALL 1

/* lookup_bdev() wants mode arg */
/* #undef HAVE_MODE_LOOKUP_BDEV */

/* Define if host toolchain supports MOVBE */
#define HAVE_MOVBE 1

/* new_sync_read()/new_sync_write() are available */
/* #undef HAVE_NEW_SYNC_READ */

/* folio_wait_bit() exists */
/* #undef HAVE_PAGEMAP_FOLIO_WAIT_BIT */

/* iops->getattr() takes a path */
#define HAVE_PATH_IOPS_GETATTR 1

/* Define if host toolchain supports PCLMULQDQ */
#define HAVE_PCLMULQDQ 1

/* percpu_counter_add_batch() is defined */
#define HAVE_PERCPU_COUNTER_ADD_BATCH 1

/* percpu_counter_init() wants gfp_t */
#define HAVE_PERCPU_COUNTER_INIT_WITH_GFP 1

/* posix_acl_chmod() exists */
/* #undef HAVE_POSIX_ACL_CHMOD */

/* posix_acl_from_xattr() needs user_ns */
#define HAVE_POSIX_ACL_FROM_XATTR_USERNS 1

/* posix_acl_release() is available */
#define HAVE_POSIX_ACL_RELEASE 1

/* posix_acl_release() is GPL-only */
/* #undef HAVE_POSIX_ACL_RELEASE_GPL_ONLY */

/* posix_acl_valid() wants user namespace */
#define HAVE_POSIX_ACL_VALID_WITH_NS 1

/* proc_ops structure exists */
#define HAVE_PROC_OPS_STRUCT 1

/* iops->put_link() cookie */
/* #undef HAVE_PUT_LINK_COOKIE */

/* iops->put_link() delayed */
#define HAVE_PUT_LINK_DELAYED 1

/* iops->put_link() nameidata */
/* #undef HAVE_PUT_LINK_NAMEIDATA */

/* If available, contains the Python version number currently in use. */
/* #undef HAVE_PYTHON */

/* qat is enabled and existed */
/* #undef HAVE_QAT */

/* iops->rename() wants flags */
#define HAVE_RENAME_WANTS_FLAGS 1

/* REQ_DISCARD is defined */
/* #undef HAVE_REQ_DISCARD */

/* REQ_FLUSH is defined */
/* #undef HAVE_REQ_FLUSH */

/* REQ_OP_DISCARD is defined */
#define HAVE_REQ_OP_DISCARD 1

/* REQ_OP_FLUSH is defined */
#define HAVE_REQ_OP_FLUSH 1

/* REQ_OP_SECURE_ERASE is defined */
#define HAVE_REQ_OP_SECURE_ERASE 1

/* REQ_PREFLUSH is defined */
#define HAVE_REQ_PREFLUSH 1

/* revalidate_disk() is available */
/* #undef HAVE_REVALIDATE_DISK */

/* revalidate_disk_size() is available */
#define HAVE_REVALIDATE_DISK_SIZE 1

/* struct rw_semaphore has member activity */
/* #undef HAVE_RWSEM_ACTIVITY */

/* struct rw_semaphore has atomic_long_t member count */
#define HAVE_RWSEM_ATOMIC_LONG_COUNT 1

/* linux/sched/signal.h exists */
#define HAVE_SCHED_SIGNAL_HEADER 1

/* Define to 1 if you have the <security/pam_modules.h> header file. */
/* #undef HAVE_SECURITY_PAM_MODULES_H */

/* setattr_prepare() is available, doesn't accept user_namespace */
#define HAVE_SETATTR_PREPARE_NO_USERNS 1

/* setattr_prepare() accepts user_namespace */
/* #undef HAVE_SETATTR_PREPARE_USERNS */

/* iops->set_acl() exists, takes 3 args */
#define HAVE_SET_ACL 1

/* iops->set_acl() takes 4 args */
/* #undef HAVE_SET_ACL_USERNS */

/* set_cached_acl() is usable */
#define HAVE_SET_CACHED_ACL_USABLE 1

/* set_special_state() exists */
#define HAVE_SET_SPECIAL_STATE 1

/* struct shrink_control exists */
#define HAVE_SHRINK_CONTROL_STRUCT 1

/* kernel_siginfo_t exists */
#define HAVE_SIGINFO 1

/* signal_stop() exists */
#define HAVE_SIGNAL_STOP 1

/* new shrinker callback wants 2 args */
/* #undef HAVE_SINGLE_SHRINKER_CALLBACK */

/* ->count_objects exists */
#define HAVE_SPLIT_SHRINKER_CALLBACK 1

/* Define if host toolchain supports SSE */
#define HAVE_SSE 1

/* Define if host toolchain supports SSE2 */
#define HAVE_SSE2 1

/* Define if host toolchain supports SSE3 */
#define HAVE_SSE3 1

/* Define if host toolchain supports SSE4.1 */
#define HAVE_SSE4_1 1

/* Define if host toolchain supports SSE4.2 */
#define HAVE_SSE4_2 1

/* Define if host toolchain supports SSSE3 */
#define HAVE_SSSE3 1

/* STACK_FRAME_NON_STANDARD is defined */
#define HAVE_STACK_FRAME_NON_STANDARD 1

/* standalone <linux/stdarg.h> exists */
/* #undef HAVE_STANDALONE_LINUX_STDARG */

/* Define to 1 if you have the <stdint.h> header file. */
#define HAVE_STDINT_H 1

/* Define to 1 if you have the <stdlib.h> header file. */
#define HAVE_STDLIB_H 1

/* Define to 1 if you have the <strings.h> header file. */
#define HAVE_STRINGS_H 1

/* Define to 1 if you have the <string.h> header file. */
#define HAVE_STRING_H 1

/* Define to 1 if you have the `strlcat' function. */
/* #undef HAVE_STRLCAT */

/* Define to 1 if you have the `strlcpy' function. */
/* #undef HAVE_STRLCPY */

/* submit_bio is member of struct block_device_operations */
#define HAVE_SUBMIT_BIO_IN_BLOCK_DEVICE_OPERATIONS 1

/* super_setup_bdi_name() exits */
#define HAVE_SUPER_SETUP_BDI_NAME 1

/* super_block->s_user_ns exists */
#define HAVE_SUPER_USER_NS 1

/* Define to 1 if you have the <sys/stat.h> header file. */
#define HAVE_SYS_STAT_H 1

/* Define to 1 if you have the <sys/types.h> header file. */
#define HAVE_SYS_TYPES_H 1

/* i_op->tmpfile() exists */
#define HAVE_TMPFILE 1

/* i_op->tmpfile() has userns */
/* #undef HAVE_TMPFILE_USERNS */

/* totalhigh_pages() exists */
#define HAVE_TOTALHIGH_PAGES 1

/* kernel has totalram_pages() */
#define HAVE_TOTALRAM_PAGES_FUNC 1

/* Define to 1 if you have the `udev_device_get_is_initialized' function. */
#define HAVE_UDEV_DEVICE_GET_IS_INITIALIZED 1

/* kernel has __kernel_fpu_* functions */
/* #undef HAVE_UNDERSCORE_KERNEL_FPU */

/* Define to 1 if you have the <unistd.h> header file. */
#define HAVE_UNISTD_H 1

/* iops->getattr() takes struct user_namespace* */
/* #undef HAVE_USERNS_IOPS_GETATTR */

/* iops->getattr() takes a vfsmount */
/* #undef HAVE_VFSMOUNT_IOPS_GETATTR */

/* aops->direct_IO() uses iovec */
/* #undef HAVE_VFS_DIRECT_IO_IOVEC */

/* aops->direct_IO() uses iov_iter without rw */
#define HAVE_VFS_DIRECT_IO_ITER 1

/* aops->direct_IO() uses iov_iter with offset */
/* #undef HAVE_VFS_DIRECT_IO_ITER_OFFSET */

/* aops->direct_IO() uses iov_iter with rw and offset */
/* #undef HAVE_VFS_DIRECT_IO_ITER_RW_OFFSET */

/* All required iov_iter interfaces are available */
#define HAVE_VFS_IOV_ITER 1

/* fops->iterate() is available */
/* #undef HAVE_VFS_ITERATE */

/* fops->iterate_shared() is available */
#define HAVE_VFS_ITERATE_SHARED 1

/* fops->readdir() is available */
/* #undef HAVE_VFS_READDIR */

/* fops->read/write_iter() are available */
#define HAVE_VFS_RW_ITERATE 1

/* __set_page_dirty_nobuffers exists */
#define HAVE_VFS_SET_PAGE_DIRTY_NOBUFFERS 1

/* __vmalloc page flags exists */
/* #undef HAVE_VMALLOC_PAGE_KERNEL */

/* yes */
/* #undef HAVE_WAIT_ON_BIT_ACTION */

/* wait_queue_entry_t exists */
#define HAVE_WAIT_QUEUE_ENTRY_T 1

/* wq_head->head and wq_entry->entry exist */
#define HAVE_WAIT_QUEUE_HEAD_ENTRY 1

/* xattr_handler->get() wants dentry */
/* #undef HAVE_XATTR_GET_DENTRY */

/* xattr_handler->get() wants both dentry and inode */
#define HAVE_XATTR_GET_DENTRY_INODE 1

/* xattr_handler->get() wants xattr_handler */
/* #undef HAVE_XATTR_GET_HANDLER */

/* xattr_handler has name */
#define HAVE_XATTR_HANDLER_NAME 1

/* xattr_handler->list() wants dentry */
/* #undef HAVE_XATTR_LIST_DENTRY */

/* xattr_handler->list() wants xattr_handler */
/* #undef HAVE_XATTR_LIST_HANDLER */

/* xattr_handler->list() wants simple */
#define HAVE_XATTR_LIST_SIMPLE 1

/* xattr_handler->set() wants dentry */
/* #undef HAVE_XATTR_SET_DENTRY */

/* xattr_handler->set() wants both dentry and inode */
#define HAVE_XATTR_SET_DENTRY_INODE 1

/* xattr_handler->set() wants xattr_handler */
/* #undef HAVE_XATTR_SET_HANDLER */

/* xattr_handler->set() takes user_namespace */
/* #undef HAVE_XATTR_SET_USERNS */

/* Define if you have [z] */
#define HAVE_ZLIB 1

/* __posix_acl_chmod() exists */
#define HAVE___POSIX_ACL_CHMOD 1

/* kernel exports FPU functions */
#define KERNEL_EXPORTS_X86_FPU 1

/* Define to the sub-directory where libtool stores uninstalled libraries. */
#define LT_OBJDIR ".libs/"

/* make_request_fn() return type */
/* #undef MAKE_REQUEST_FN_RET */

/* hardened module_param_call */
#define MODULE_PARAM_CALL_CONST 1

/* struct shrink_control has nid */
#define SHRINK_CONTROL_HAS_NID 1

/* Defined for legacy compatibility. */
#define SPL_META_ALIAS ZFS_META_ALIAS

/* Defined for legacy compatibility. */
#define SPL_META_RELEASE ZFS_META_RELEASE

/* Defined for legacy compatibility. */
#define SPL_META_VERSION ZFS_META_VERSION

/* True if ZFS is to be compiled for a FreeBSD system */
/* #undef SYSTEM_FREEBSD */

/* True if ZFS is to be compiled for a Linux system */
#define SYSTEM_LINUX 1

/* zfs debugging enabled */
/* #undef ZFS_DEBUG */

/* /dev/zfs minor */
#define ZFS_DEVICE_MINOR 249

/* enum node_stat_item contains NR_FILE_PAGES */
#define ZFS_ENUM_NODE_STAT_ITEM_NR_FILE_PAGES 1

/* enum node_stat_item contains NR_INACTIVE_ANON */
#define ZFS_ENUM_NODE_STAT_ITEM_NR_INACTIVE_ANON 1

/* enum node_stat_item contains NR_INACTIVE_FILE */
#define ZFS_ENUM_NODE_STAT_ITEM_NR_INACTIVE_FILE 1

/* enum zone_stat_item contains NR_FILE_PAGES */
/* #undef ZFS_ENUM_ZONE_STAT_ITEM_NR_FILE_PAGES */

/* enum zone_stat_item contains NR_INACTIVE_ANON */
/* #undef ZFS_ENUM_ZONE_STAT_ITEM_NR_INACTIVE_ANON */

/* enum zone_stat_item contains NR_INACTIVE_FILE */
/* #undef ZFS_ENUM_ZONE_STAT_ITEM_NR_INACTIVE_FILE */

/* global_node_page_state() exists */
#define ZFS_GLOBAL_NODE_PAGE_STATE 1

/* global_zone_page_state() exists */
#define ZFS_GLOBAL_ZONE_PAGE_STATE 1

/* Define to 1 if GPL-only symbols can be used */
/* #undef ZFS_IS_GPL_COMPATIBLE */

/* Define the project alias string. */
#define ZFS_META_ALIAS "zfs-2.1.2-1"

/* Define the project author. */
#define ZFS_META_AUTHOR "OpenZFS"

/* Define the project release date. */
/* #undef ZFS_META_DATA */

/* Define the maximum compatible kernel version. */
#define ZFS_META_KVER_MAX "5.15"

/* Define the minimum compatible kernel version. */
#define ZFS_META_KVER_MIN "3.10"

/* Define the project license. */
#define ZFS_META_LICENSE "CDDL"

/* Define the libtool library 'age' version information. */
/* #undef ZFS_META_LT_AGE */

/* Define the libtool library 'current' version information. */
/* #undef ZFS_META_LT_CURRENT */

/* Define the libtool library 'revision' version information. */
/* #undef ZFS_META_LT_REVISION */

/* Define the project name. */
#define ZFS_META_NAME "zfs"

/* Define the project release. */
#define ZFS_META_RELEASE "1"

/* Define the project version. */
#define ZFS_META_VERSION "2.1.2"

/* count is located in percpu_ref.data */
#define ZFS_PERCPU_REF_COUNT_IN_DATA 1

