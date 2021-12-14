obj-m += drbd.o drbd_transport_tcp.o


# The augmented rbtree helper functions are not exported at least until kernel
# version 2.6.38-rc2.
#ifeq ($(shell grep -e '\<rb_augment_insert\>' \
#		   -e '\<rb_augment_erase_begin\>' \
#		   -e '\<rb_augment_erase_end\>' \
#		   $(objtree)/Module.symvers | wc -l),3)
#override EXTRA_CFLAGS += -DAUGMENTED_RBTREE_SYMBOLS_EXPORTED
#endif
#
# NOTE: That copy-pasted comment doesn't seem entirely true... 5.4 -
#       5.10 do NOT export those symbols.
#
#override EXTRA_CFLAGS += -DAUGMENTED_RBTREE_SYMBOLS_EXPORTED


#ifeq ($(shell grep -e '\<blkdev_issue_zeroout\>' \
#		   $(objtree)/Module.symvers | wc -l),1)
#override EXTRA_CFLAGS += -DBLKDEV_ISSUE_ZEROOUT_EXPORTED
#else
#compat_objs += drbd-kernel-compat/blkdev_issue_zeroout.o
#endif
#
# NOTE: 5.4 - 5.10 look good
#
override EXTRA_CFLAGS += -DBLKDEV_ISSUE_ZEROOUT_EXPORTED


#ifneq ($(shell grep -e '\<nsecs_to_jiffies\>' \
#		   $(objtree)/Module.symvers | wc -l),1)
#compat_objs += drbd-kernel-compat/nsecs_to_jiffies.o
#endif
#
# NOTE: 5.4 - 5.10 look good
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
# NOTE: 5.4 - 5.10 have it, and I've got CONFIG_DEV_DAX_PMEM=m
#
drbd-y += drbd_dax_pmem.o


#
# NOTE: We yanked lru_cache.o out of here to use the mainline version.
#       I'm not 100% sure that's the right thing to do, so if things
#       go south, revisit that.
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
