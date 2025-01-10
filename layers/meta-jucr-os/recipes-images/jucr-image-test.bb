require jucr-image-base.bb
SUMMARY = "This extends jucr-minimal image for dev/test purpose"









# CORE_IMAGE_EXTRA_INSTALL += "\
#    e2fsprogs-resize2fs \
#"

# not needed i guess:
# splash, ssh-server-dropbear, read-only-rootfs, ptest-pkgs
# consider:
# dbg-pkgs, dev-pkgs, stateless-rootfs  serial-autologin-root  read-only-rootfs-delayed-postinsts (for csc)  overlayfs-etc (if a/b)
# might bloat image
EXTRA_IMAGE_FEATURES += "\
    package-management \
    ssh-server-openssh \
    allow-empty-password \
    empty-root-password \
    tools-debug \
    post-install-logging \
    debug-tweaks \
    perf \
"
