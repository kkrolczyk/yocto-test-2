DESCRIPTION = "Starman v2 firmware package group"

inherit packagegroup

RDEPENDS:${PN} = "\
  starman-v2-fw-ac \
  starman-v2-fw-cc \
  starman-v2-fw-ui \
  starman-v2-fw-cm \
"
