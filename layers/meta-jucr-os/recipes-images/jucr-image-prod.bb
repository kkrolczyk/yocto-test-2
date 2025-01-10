require jucr-image-base.bb
SUMMARY = "This extends jucr-minimal image for release purpose"





# consider if any are needed. Optionally: package-management
EXTRA_IMAGE_FEATURES += "\
    package-management \
    ssh-server-openssh \
"
