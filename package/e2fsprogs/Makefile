# 
# Copyright (C) 2006 OpenWrt.org
#
# This is free software, licensed under the GNU General Public License v2.
# See /LICENSE for more information.
#
# $Id: Makefile 8172 2007-07-26 11:46:20Z kaloz $

include $(TOPDIR)/rules.mk

PKG_NAME:=e2fsprogs
PKG_VERSION:=1.39
PKG_RELEASE:=1

PKG_SOURCE:=$(PKG_NAME)-$(PKG_VERSION).tar.gz
PKG_SOURCE_URL:=@SF/e2fsprogs
PKG_MD5SUM:=06f7806782e357797fad1d34b7ced0c6

include $(INCLUDE_DIR)/package.mk

define Package/e2fsprogs
  SECTION:=utils
  CATEGORY:=Utilities
  TITLE:=Ext2/3 filesystem utilities
  DEPENDS:=+libuuid
endef

define Package/libuuid
  SECTION:=libs
  CATEGORY:=Libraries
  TITLE:=DCE compatible Universally Unique Identifier library
  URL:=http://e2fsprogs.sourceforge.net/
endef

define Package/libblkid
  SECTION:=libs
  CATEGORY:=Libraries
  TITLE:=block device id library
  URL:=http://e2fsprogs.sourceforge.net/
endef

define Package/tune2fs
  $(call Package/e2fsprogs)
  TITLE:=Ext2 Filesystem tune utility
  DEPENDS:=e2fsprogs
endef

define Package/resize2fs
  $(call Package/e2fsprogs)
  TITLE:=Ext2 Filesystem resize utility
  DEPENDS:=e2fsprogs
endef

CONFIGURE_ARGS += \
	--enable-shared \
	--enable-static \
	--disable-rpath \
	--enable-elf-shlibs \
	--enable-dynamic-e2fsck

define Build/Prepare
	$(call Build/Prepare/Default)
	$(CP) $(SCRIPT_DIR)/config.{guess,sub} $(PKG_BUILD_DIR)/config/
endef

define Build/Compile
	$(MAKE) -C $(PKG_BUILD_DIR)/util \
		BUILDCC="$(HOSTCC)" \
		CFLAGS="" \
		CPPFLAGS="" \
		LDFLAGS="" \
		subst
	$(MAKE) -C $(PKG_BUILD_DIR) \
		BUILDCC="$(HOSTCC)" \
		DESTDIR="$(PKG_INSTALL_DIR)" \
		all install
endef

define Build/InstallDev
	$(MAKE) -C $(PKG_BUILD_DIR) \
		BUILDCC="$(HOSTCC)" \
		DESTDIR="$(STAGING_DIR)" \
		install-libs
endef

define Package/e2fsprogs/install
	$(INSTALL_DIR) $(1)/usr/sbin
	$(CP) $(PKG_INSTALL_DIR)/usr/sbin/e2fsck $(1)/usr/sbin/
	$(CP) $(PKG_INSTALL_DIR)/usr/sbin/mke2fs $(1)/usr/sbin/
	ln -sf mke2fs $(1)/usr/sbin/mkfs.ext2
	ln -sf mke2fs $(1)/usr/sbin/mkfs.ext3
	$(INSTALL_DIR) $(1)/usr/lib
	$(CP) $(foreach lib,blkid com_err e2p ext2fs,$(PKG_INSTALL_DIR)/usr/lib/lib$(lib).so.*) $(1)/usr/lib/
endef

define Package/libuuid/install
	$(INSTALL_DIR) $(1)/usr/lib
	$(CP) $(PKG_INSTALL_DIR)/usr/lib/libuuid.so.* $(1)/usr/lib/
endef

define Package/libblkid/install
	$(INSTALL_DIR) $(1)/usr/lib/
	$(CP) $(PKG_INSTALL_DIR)/usr/lib/libblkid.so.* $(1)/usr/lib/
endef

define Package/tune2fs/install
	$(INSTALL_DIR) $(1)/usr/sbin
	$(CP) $(PKG_INSTALL_DIR)/usr/sbin/tune2fs $(1)/usr/sbin/
endef

define Package/resize2fs/install
	$(INSTALL_DIR) $(1)/usr/sbin
	$(CP) $(PKG_INSTALL_DIR)/usr/sbin/resize2fs $(1)/usr/sbin/
endef

$(eval $(call BuildPackage,e2fsprogs))
$(eval $(call BuildPackage,libuuid))
$(eval $(call BuildPackage,libblkid))
$(eval $(call BuildPackage,tune2fs))
$(eval $(call BuildPackage,resize2fs))
