ifneq ($(KBUILD_EXTMOD),)
src = /scrap/zfs/module/avl
obj = /scrap/zfs/module/avl
endif

MODULE := zavl

obj-$(CONFIG_ZFS) := $(MODULE).o

$(MODULE)-objs += avl.o
