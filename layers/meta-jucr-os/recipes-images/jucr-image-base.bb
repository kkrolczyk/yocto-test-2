# TODO: perhaps in the future inherit image instead of core-image
inherit core-image

include includes/user-creation.inc

SUMMARY = "minimal jucr img."
DESCRIPTION = "here be dragon s"
LICENSE = "MIT"

include features-default.inc

####################################################
# TODO: remove this after testing
EXTRA_IMAGE_FEATURES += "\
    package-management \
    ssh-server-openssh \
    allow-empty-password \
    empty-root-password \
    tools-debug \
    post-install-logging \
    debug-tweaks \
"
####################################################

CORE_IMAGE_EXTRA_INSTALL:append = " greengrass-bin"
