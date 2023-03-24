obj-m += drbd.o drbd_transport_tcp.o
ifdef CONFIG_INFINIBAND
obj-m += drbd_transport_rdma.o
endif


#ifneq ($(shell grep -e '\<nsecs_to_jiffies\>' \
#		   $(objtree)/Module.symvers | wc -l),1)
#compat_objs += drbd-kernel-compat/nsecs_to_jiffies.o
#endif
#
# NOTE: 5.4 - 5.10 look good, haven't double-checked since then
#


#compat_objs += drbd-kernel-compat/drbd_wrappers.o
compat_objs += drbd_wrappers.o


#ifdef CONFIG_DEV_DAX_PMEM
#ifneq ($(shell grep -e '\<arch_wb_cache_pmem\>' $(objtree)/Module.symvers | wc -l),1)
#override EXTRA_CFLAGS += -DDAX_PMEM_IS_INCOMPLETE
#else
#drbd-y += drbd_dax_pmem.o
#endif
#endif
#
# NOTE: 5.4 - 5.10 have it, haven't double-checked since then.
#
ifdef CONFIG_DEV_DAX_PMEM
drbd-y += drbd_dax_pmem.o
endif


#
# NOTE: Out-of-tree module Kbuild enables fault injection by default
#       because it always has, even though it's probably not
#       desirable.  See Christoph's comment in 1e29f68bf2d6e6f in
#       upstream repo.  We'll leave this up to .config.
#
# enable fault injection by default
#ifndef CONFIG_DRBD_FAULT_INJECTION
#       override EXTRA_CFLAGS += -DCONFIG_DRBD_FAULT_INJECTION
#endif


#
# NOTE: We yanked lru_cache.o out of here to use the mainline version.
#       I'm not 100% sure that's the right thing to do, so if things
#       go south, revisit that.
#
#       Looks like that was the right call, as now even the
#       out-of-tree build system uses the in-tree lru_cache.
#
drbd-$(CONFIG_DEBUG_FS) += drbd_debugfs.o
drbd-y += drbd_buildtag.o drbd_bitmap.o drbd_proc.o
drbd-y += drbd_sender.o drbd_receiver.o drbd_req.o drbd_actlog.o
drbd-y += drbd_main.o drbd_strings.o drbd_nl.o
drbd-y += drbd_interval.o drbd_state.o $(compat_objs)
drbd-y += drbd_nla.o drbd_transport.o

ifdef CONFIG_KREF_DEBUG
      drbd-y += kref_debug.o drbd_kref_debug.o
endif


#HOST_EXTRACFLAGS += -I$(src) -std=c11 $(EXTRA_CFLAGS)
#hostprogs := drbd-kernel-compat/gen_patch_names
#headers-to-apply-compat := drbd_int.h drbd_req.h drbd_interval.h
#
#$(obj)/dummy-for-compat-h.o: $(obj)/compat.h
#	@true
#$(addprefix $(obj)/,$(drbd-y) drbd_transport_tcp.o): $(obj)/compat.h $(src)/.compat_patches_applied
#$(obj)/drbd-kernel-compat/gen_patch_names: $(src)/drbd-kernel-compat/gen_patch_names.c $(obj)/compat.h


obj-$(CONFIG_BLK_DEV_DRBD)     += drbd.o
