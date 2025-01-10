# Distro wide settings for qemu

# increase original memory from 256 to 2048
QB_MEM ?= "-m 2048"

# Always use kvm for speediness
QEMU_USE_KVM ?= "1"

# Enable libusb support (needed for usb passthrough with qemu-xhci)
PACKAGECONFIG_append_pn-qemu-native = " libusb"
PACKAGECONFIG_append_pn-nativesdk-qemu = " libusb"
