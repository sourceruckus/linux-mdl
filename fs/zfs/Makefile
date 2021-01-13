include Kbuild

INSTALL_MOD_DIR ?= extra

SUBDIR_TARGETS = icp lua zstd

all: modules
distclean maintainer-clean: clean
install: modules_install
uninstall: modules_uninstall
check:

.PHONY: all distclean maintainer-clean install uninstall check distdir \
	modules modules-Linux modules-FreeBSD modules-unknown \
	clean clean-Linux clean-FreeBSD \
	modules_install modules_install-Linux modules_install-FreeBSD \
	modules_uninstall modules_uninstall-Linux modules_uninstall-FreeBSD

# Filter out options that FreeBSD make doesn't understand
getflags = ( \
set -- \
  $(filter-out --%,$(firstword $(MFLAGS))) \
  $(filter -I%,$(MFLAGS)) \
  $(filter -j%,$(MFLAGS)); \
fmakeflags=""; \
while getopts :deiI:j:knqrstw flag; do \
  case $$flag in \
    \?) :;; \
    :) if [ $$OPTARG = "j" ]; then \
	 ncpus=$$(sysctl -n kern.smp.cpus 2>/dev/null || :); \
	 if [ -n "$$ncpus" ]; then fmakeflags="$$fmakeflags -j$$ncpus"; fi; \
       fi;; \
    d) fmakeflags="$$fmakeflags -dA";; \
    *) fmakeflags="$$fmakeflags -$$flag$$OPTARG";; \
  esac; \
done; \
echo $$fmakeflags \
)
FMAKEFLAGS = -C /scrap/zfs/module -f Makefile.bsd $(shell $(getflags))

ifneq (/scrap/zfs/module,/scrap/zfs/module)
FMAKEFLAGS += MAKEOBJDIR=/scrap/zfs/module
endif
FMAKE = env -u MAKEFLAGS make $(FMAKEFLAGS)

modules-Linux:
	list='$(SUBDIR_TARGETS)'; for targetdir in $$list; do \
		$(MAKE) -C $$targetdir; \
	done
	$(MAKE) -C /scrap/linux-mdl-5.10 M=`pwd`  CONFIG_ZFS=m modules

modules-FreeBSD:
	+$(FMAKE)

modules-unknown:
	@true

modules: modules-Linux

clean-Linux:
	@# Only cleanup the kernel build directories when CONFIG_KERNEL
	@# is defined.  This indicates that kernel modules should be built.
#	$(MAKE) -C /scrap/linux-mdl-5.10 M=`pwd`  clean

	if [ -f NONE ]; then $(RM) NONE; fi
	if [ -f Module.markers ]; then $(RM) Module.markers; fi

	find . -name '*.ur-safe' -type f -print | xargs $(RM)

clean-FreeBSD:
	+$(FMAKE) clean

clean: clean-Linux

modules_install-Linux:
	@# Install the kernel modules
	$(MAKE) -C /scrap/linux-mdl-5.10 M=`pwd` modules_install \
		INSTALL_MOD_PATH=$(DESTDIR)$(INSTALL_MOD_PATH) \
		INSTALL_MOD_DIR=$(INSTALL_MOD_DIR) \
		KERNELRELEASE=5.10.5-mdl+
	@# Remove extraneous build products when packaging
	kmoddir=$(DESTDIR)$(INSTALL_MOD_PATH)/lib/modules/5.10.5-mdl+; \
	if [ -n "$(DESTDIR)" ]; then \
		find $$kmoddir -name 'modules.*' | xargs $(RM); \
	fi
	sysmap=$(DESTDIR)$(INSTALL_MOD_PATH)/boot/System.map-5.10.5-mdl+; \
	if [ -f $$sysmap ]; then \
		depmod -ae -F $$sysmap 5.10.5-mdl+; \
	fi

modules_install-FreeBSD:
	@# Install the kernel modules
	+$(FMAKE) install

modules_install: modules_install-Linux

modules_uninstall-Linux:
	@# Uninstall the kernel modules
	kmoddir=$(DESTDIR)$(INSTALL_MOD_PATH)/lib/modules/5.10.5-mdl+; \
	for objdir in $(ZFS_MODULES); do \
		$(RM) -R $$kmoddir/$(INSTALL_MOD_DIR)/$$objdir; \
	done

modules_uninstall-FreeBSD:
	@false

modules_uninstall: modules_uninstall-Linux

distdir:
	(cd . && find $(ZFS_MODULES) os -name '*.[chS]') | \
	while read path; do \
		mkdir -p $$distdir/$${path%/*}; \
		cp ./$$path $$distdir/$$path; \
	done; \
	cp ./Makefile.bsd $$distdir/Makefile.bsd
