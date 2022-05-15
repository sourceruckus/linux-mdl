include Kbuild

INSTALL_MOD_DIR ?= extra
INSTALL_MOD_PATH ?= $(DESTDIR)

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
	modules_uninstall modules_uninstall-Linux modules_uninstall-FreeBSD \
	cppcheck cppcheck-Linux cppcheck-FreeBSD

# For FreeBSD, use debug options from ./configure if not overridden.
export WITH_DEBUG ?= 
export WITH_INVARIANTS ?= 

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
	list='$(SUBDIR_TARGETS)'; for td in $$list; do $(MAKE) -C $$td; done
	$(MAKE) -C /scrap/linux-mdl-5.10 $(if ,CC=) \
		$(if ,LD=) $(if ,LLVM=) \
		M="$$PWD"  CONFIG_ZFS=m modules

modules-FreeBSD:
	+$(FMAKE)

modules-unknown:
	@true

modules: modules-Linux

clean-Linux:
	@# Only cleanup the kernel build directories when CONFIG_KERNEL
	@# is defined.  This indicates that kernel modules should be built.
#	$(MAKE) -C /scrap/linux-mdl-5.10 M="$$PWD"  clean

	$(RM) NONE Module.markers
	find . -name '*.ur-safe' -type f -delete

clean-FreeBSD:
	+$(FMAKE) clean

clean: clean-Linux

modules_install-Linux:
	@# Install the kernel modules
	$(MAKE) -C /scrap/linux-mdl-5.10 M="$$PWD" modules_install \
		INSTALL_MOD_PATH=$(INSTALL_MOD_PATH) \
		INSTALL_MOD_DIR=$(INSTALL_MOD_DIR) \
		KERNELRELEASE=5.10.115-mdl+
	@# Remove extraneous build products when packaging
	kmoddir=$(INSTALL_MOD_PATH)/lib/modules/5.10.115-mdl+; \
	if [ -n "$(DESTDIR)" ]; then \
		find $$kmoddir -name 'modules.*' -delete; \
	fi
	@# Debian ships tiny fake System.map files that are
	@# syntactically valid but just say
	@# "if you want system.map go install this package"
	@# Naturally, depmod is less than amused by this.
	@# So if we find it missing or with one of these present,
	@# we check for the alternate path for the System.map
	sysmap=$(INSTALL_MOD_PATH)/boot/System.map-5.10.115-mdl+; \
	{ [ -f "$$sysmap" ] && [ $$(wc -l < "$$sysmap") -ge 100 ]; } || \
		sysmap=$(INSTALL_MOD_PATH)/usr/lib/debug/boot/System.map-5.10.115-mdl+; \
	if [ -f $$sysmap ]; then \
		depmod -ae -F $$sysmap 5.10.115-mdl+; \
	fi

modules_install-FreeBSD:
	@# Install the kernel modules
	+$(FMAKE) install

modules_install: modules_install-Linux

modules_uninstall-Linux:
	@# Uninstall the kernel modules
	kmoddir=$(INSTALL_MOD_PATH)/lib/modules/5.10.115-mdl+; \
	for objdir in $(ZFS_MODULES); do \
		$(RM) -R $$kmoddir/$(INSTALL_MOD_DIR)/$$objdir; \
	done

modules_uninstall-FreeBSD:
	@false

modules_uninstall: modules_uninstall-Linux

cppcheck-Linux:
	 -j16 --std=c99 --quiet --force --error-exitcode=2 \
		--inline-suppr \
		--suppress=unmatchedSuppression \
		--suppress=noValidConfiguration \
		--enable=warning,information -D_KERNEL \
		--include=/scrap/linux-mdl-5.10/include/generated/autoconf.h \
		--include=../zfs_config.h \
		--config-exclude=/scrap/linux-mdl-5.10/include \
		-I /scrap/linux-mdl-5.10/include \
		-I ../include/os/linux/kernel \
		-I ../include/os/linux/spl \
		-I ../include/os/linux/zfs \
		-I ../include \
		avl icp lua nvpair spl unicode zcommon zfs zstd os/linux

cppcheck-FreeBSD:
	@true

cppcheck: cppcheck-Linux

distdir:
	(cd . && find $(ZFS_MODULES) os -name '*.[chS]') | \
	while read path; do \
		mkdir -p $$distdir/$${path%/*}; \
		cp ./$$path $$distdir/$$path; \
	done; \
	cp ./Makefile.bsd $$distdir/Makefile.bsd
