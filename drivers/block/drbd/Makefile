obj-m += drbd.o drbd_transport_tcp.o drbd_transport_lb-tcp.o
ifdef CONFIG_INFINIBAND
obj-m += drbd_transport_rdma.o
endif


#clean-files := compat.h $(wildcard .config.$(KERNELVERSION).timestamp)


# PRE_CFLAGS may contain (M)OFED header locations
#LINUXINCLUDE := $(PRE_CFLAGS) -I$(src) -I$(src)/drbd-headers $(LINUXINCLUDE)


# Files in the standard include directories take precendence over files
# in the drbd-kernel-compat directory.
#
# Add -I$(src) to EXTRA_CFLAGS again: some (rhel5, maybe other) kbuild does not
# yet use LINUXINCLUDE like we expect it to ;( fortunately it does not contain
# in-tree drbd either yet, so precedence of include files is not important.
#
# override: we absolutely need this, even if EXTRA_CFLAGS originates from make
# command line or environment
#override EXTRA_CFLAGS += -I$(src) -I$(src)/drbd-kernel-compat
override EXTRA_CFLAGS += -I$(src)


#ifneq ($(shell grep -e '\<nsecs_to_jiffies\>' \
#		   $(objtree)/Module.symvers | wc -l),1)
#compat_objs += drbd-kernel-compat/nsecs_to_jiffies.o
#endif
#
# NOTE: 5.4 - 5.10 look good, haven't double-checked since then
#


#ifndef CONFIG_LRU_CACHE
#compat_objs += drbd-kernel-compat/lru_cache.o
#endif
#
# NOTE: we just make sure LRU_CACHE is enabled in .config
#


#ifeq ($(shell test $(VERSION) -ge 4; echo $$?),0)
#ifeq ($(shell test $(VERSION) -gt 4 || test $(PATCHLEVEL) -ge 17; echo $$?),0)
#ifndef CONFIG_NET_HANDSHAKE
#obj-$(CONFIG_TLS) += drbd-kernel-compat/handshake/
#$(obj)/drbd-kernel-compat/handshake: $(obj)/compat.h $(src)/.compat_patches_applied
#endif
#endif
#endif
#
# NOTE: We DO need this net/handshake compat code for 5.15.
#
obj-$(CONFIG_TLS) += handshake/


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
