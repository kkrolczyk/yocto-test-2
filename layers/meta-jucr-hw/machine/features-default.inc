MACHINE_ESSENTIAL_EXTRA_RECOMMENDS += "kernel-modules"

# https://docs.yoctoproject.org/5.0.5/ref-manual/features.html#ref-features-backfill
# consider (SoM Dart doesn't have RTC connected):
# MACHINE_FEATURES_BACKFILL_CONSIDERED += "rtc"

MACHINE_FEATURES:remove =" acpi alsa ext2 keyboard pci pcmcia phone qvga screen touchscreen vfat "

# REMOVED
#########
# acpi: Hardware has ACPI (x86/x86_64 only)
# alsa: Hardware has ALSA audio drivers
# ext2: Hardware HDD or Microdrive
# keyboard: Hardware has a keyboard
# pci: Hardware has a PCI bus
# pcmcia: Hardware has PCMCIA or CompactFlash sockets
# phone: Mobile phone (voice) support
# qvga: Machine has a QVGA (320x240) display
# screen: Hardware has a screen
# touchscreen: Hardware has a touchscreen
# vfat: FAT file system support

# KEPT
######
# bluetooth: Hardware has integrated BT
# efi: Support for booting through EFI
# numa: Hardware has non-uniform memory access
# pcbios: Support for booting through BIOS
# qemu-usermode: QEMU can support user-mode emulation for this machine
# rtc: Machine has a Real-Time Clock
# serial: Hardware has serial support (usually RS232)
# usbgadget: Hardware is USB gadget device capable
# usbhost: Hardware is USB Host capable
# wifi: Hardware has integrated WiFi
