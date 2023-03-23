ifneq ($(KBUILD_EXTMOD),)
src = /scrap/zfs/module/spl
obj = /scrap/zfs/module/spl
mfdir = $(obj)
else
mfdir = $(srctree)/$(src)
endif

MODULE := spl

obj-$(CONFIG_ZFS) := $(MODULE).o

include $(mfdir)/../os/linux/spl/Makefile
