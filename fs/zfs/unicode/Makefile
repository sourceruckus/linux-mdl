ifneq ($(KBUILD_EXTMOD),)
src = /scrap/zfs/module/unicode
obj = /scrap/zfs/module/unicode
endif

MODULE := zunicode

obj-$(CONFIG_ZFS) := $(MODULE).o

$(MODULE)-objs += u8_textprep.o
$(MODULE)-objs += uconv.o
