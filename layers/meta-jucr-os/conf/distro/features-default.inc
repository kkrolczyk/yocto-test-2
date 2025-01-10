DISTRO_EXTRA_RDEPENDS += "packagegroup-core-boot"

# See bottom of this file for full list
DISTRO_FEATURES = " 3g ipv4 ipv6 ldconfig ppp systemd usbgadget usbhost wifi xattr "

# TODO: not needed, we define only which we want above...  #  multiarch vulkan  virtualization   pam/selinux/apparmor/smack/acl/seccomp
# DISTRO_FEATURES_DEFAULT:remove = " alsa api-documentation bluetooth cramfs directfb ipsec nfs opengl ptest smbfs x11 wayland    nfc "
# see "features.list" for descriptions
# What do we do with (do we want them?):
#                 -> ext2 keyboard pci pcmcia usrmerge(is it wanted?) 3g? nfc?

DISTRO_FEATURES_BACKFILL_CONSIDERED += "gobject-introspection-data pulseaudio bluez4 bluez5"

# required for AWS Greengrass
DISTRO_FEATURES += "systemd ntp-systemd"
DISTRO_FEATURES_BACKFILL_CONSIDERED = "sysvinit"
# TODO: consider (for base!) "mdev-busybox"
INIT_MANAGER = "systemd"
VIRTUAL-RUNTIME_init_manager = "systemd"
VIRTUAL-RUNTIME_initscripts = ""


# TODO
PREFERRED_PROVIDER_virtual/kernel = "linux-yocto"
PREFERRED_VERSION_linux-yocto ?= "6.6%"
# PREFERRED_PROVIDER_virtual/kernel = "linux-kernel"

# use DEBs / RPMs (package_rpm) instead of IPK?
# PACKAGE_CLASSES ?= "package_deb"

# smaller (also when no pkg management on target, like on  core-image-minimal)
PACKAGE_CLASSES += "package_ipk"


# see poky-tiny for reasons
USE_NLS = "no"
IMAGE_LINGUAS = ""
ENABLE_WIDEC = "false"
ENABLE_WIDEC:class-native = "true"





# TODO: ARE THOSE NEEDED?
# LOCALCONF_VERSION = "2"

# Disable python usage in opkg-utils since it won't build with tiny config
# PACKAGECONFIG:remove:pn-opkg-utils = "python"

## IDK rather not
## DISTRO_FEATURES:class-native = "${DISTRO_FEATURES_DEFAULT} ${POKY_DEFAULT_DISTRO_FEATURES}"










# ------------------------------------------------------------------------

# DISTRO_FEATURES
# alsa: Include ALSA support
# api-documentation: Enables generation of API documentation
# bluetooth: Include integrated bluetooth support
# cramfs: Include CramFS support
# directfb: Include DirectFB support
# ext2: tools
# ipsec: Include IPSec support
# ipv6: Include IPv6 support
# keyboard: Include keyboard support
# ldconfig: Include support for ldconfig and ld.so.conf on the target.
# nfs: Include NFS client support
# opengl: Include the Open Graphics Library
# pci: Include PCI bus support
# pcmcia: Include PCMCIA/CompactFlash support
# ppp: Include PPP dialup support
# ptest: Enables building the package tests
# smbfs: Include SMB networks client support
# systemd: Include support for this init manager
# usbgadget: Include USB Gadget Device support (for USB networking/serial/storage).
# usbhost: Include USB Host support (allows to connect external keyboard, mouse, storage, network etc).
# usrmerge: Merges the /bin, /sbin, /lib, and /lib64 directories into their respective counterparts in the /usr directory to provide better package and application compatibility
# wayland: Include the Wayland
# wifi: Include integrated WiFi support
# x11: Include the X server and libraries
# zeroconf ??

