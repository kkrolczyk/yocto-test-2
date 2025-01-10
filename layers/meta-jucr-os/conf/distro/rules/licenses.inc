# This file contains all the settings regarding
# licenses, blacklisting/whitelisting a.s.o.

# Blacklist a set of license that we don't want in the image
INCOMPATIBLE_LICENSE ?= "\
    GPL-3.0 \
    LGPL-3.0 \
    AGPL-3.0 \
    MPL-1.1 \
    SGI-1 \
    CECILL-2.0 \
    CDDL-1.1 \
    EPL-1.0 \
    CPL-1.0 \
"

# whitelist GPL licenses for some packages
WHITELIST_GPL-3.0 ?= "\
    binutils \
    gdb \
    gdbserver \
"
WHITELIST_LGPL-3.0 ?= "gdb"

LICENSE_FLAGS_WHITELIST += "\
"
