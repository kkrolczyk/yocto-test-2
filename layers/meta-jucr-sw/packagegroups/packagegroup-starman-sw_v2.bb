DESCRIPTION = "Starman v2 software package group"

inherit packagegroup

RDEPENDS:${PN} = "\
  starman-v2-sw-ac \
  starman-v2-sw-cc \
  starman-v2-sw-ui \
  starman-v2-sw-cm \
"
