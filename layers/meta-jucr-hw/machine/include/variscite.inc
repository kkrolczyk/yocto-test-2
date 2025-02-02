require variscite-mirrors.inc
INHERIT += "image-buildinfo"

# Common override for all Variscite machines
MACHINEOVERRIDES =. "var-som:"

MACHINE_FEATURES += " pci bluetooth wifi screen"

IMX_DEFAULT_BSP = "nxp"

USE_VT = "0"

KERNEL_IMAGETYPE:mx8-nxp-bsp = "Image.gz"
KERNEL_IMAGETYPE:mx9-nxp-bsp = "Image.gz"

WKS_FILE:mx8-nxp-bsp = "imx-imx-boot-singlepart.wks.in"
WKS_FILE:mx9-nxp-bsp = "imx-imx-boot-singlepart.wks.in"

# Set a more generic tuning for code reuse across parts
DEFAULTTUNE:mx8-nxp-bsp:fslc     ?= "armv8a-crc-crypto"
DEFAULTTUNE:mx8m-nxp-bsp:fslc    ?= "armv8a-crc-crypto"
DEFAULTTUNE:mx8qxp-nxp-bsp:fslc  ?= "armv8a-crc-crypto"
DEFAULTTUNE:mx8x-nxp-bsp:fslc    ?= "armv8a-crc-crypto"

NETMAN_PACKAGES = "\
	networkmanager \
	networkmanager-nmcli \
"

# Wayland distros should default to systemd-networkd
PREFERRED_CONNECTIVITY_MANAGER	 ?= " \
	${@bb.utils.contains('DISTRO', 'b2qt', '', \
		bb.utils.contains('DISTRO_FEATURES', 'wayland', \
		'systemd-networkd', '', d), d)} \
"
PREFERRED_CONNECTIVITY_MANAGER_PACKAGES	?= " \
	${@bb.utils.contains('PREFERRED_CONNECTIVITY_MANAGER', 'networkmanager', \
		'${NETMAN_PACKAGES}','', d)} \
"

# Variscite BSP default providers
PREFERRED_RPROVIDER_u-boot-default-env ?= "u-boot-variscite"

# Use libgpiod 1.6.%
PREFERRED_VERSION_libgpiod:var-som ?= "1.6.%"

# Use i.MX Gstreamer Version
MACHINE_GSTREAMER_1_0_PLUGIN:mx6-nxp-bsp = "imx-gst1.0-plugin"
MACHINE_GSTREAMER_1_0_PLUGIN:mx7-nxp-bsp = "imx-gst1.0-plugin"
MACHINE_GSTREAMER_1_0_PLUGIN:mx8-nxp-bsp = "imx-gst1.0-plugin"

# Add VPU and Cortex M4/M7 firmware
MACHINE_FIRMWARE:append:mx8-nxp-bsp = " \
	firmware-imx-vpu-imx8 \
	freertos-variscite-dbg \
	freertos-variscite-scripts \
	"

# Add Cortex-M33 firmware
MACHINE_FIRMWARE:append:imx93-var-som = " \
	freertos-variscite \
	freertos-variscite-scripts \
	"

MACHINE_EXTRA_RDEPENDS += " \
	gptfdisk \
	hostapd \
	hdparm \
	imx-kobs \
	iw \
	kernel-modules \
	kmod \
	${PREFERRED_CONNECTIVITY_MANAGER_PACKAGES} \
	packagegroup-tools-bluetooth \
	packagegroup-var-hw-test \
	bluealsa \
	pm-utils-variscite \
	rng-tools \
	wpa-supplicant \
	wireless-regdb-static \
	u-boot-fw-utils \
	u-boot-splash \
	u-boot-default-env \
	${@bb.utils.contains('MACHINE_FEATURES', 'nxpiw612-sdio', 'iw612-utils', '', d)} \
"

# Packages added to all images (including core-image-minimal)
IMAGE_INSTALL:append:mx8-nxp-bsp = " \
	kernel-image \
	kernel-devicetree \
"

IMAGE_INSTALL:append:mx9-nxp-bsp = " \
	kernel-image \
	kernel-devicetree \
	zstd \
"

IMAGE_FSTYPES = "tar.zst wic.zst"

# Use bluez-alsa instead of pulseaudio
DISTRO_FEATURES_BACKFILL_CONSIDERED:append = " pulseaudio"

# Enable virtualization
DISTRO_FEATURES:append:mx8-nxp-bsp = " virtualization"
DISTRO_FEATURES:append:mx9-nxp-bsp = " virtualization"
