DESCRIPTION = "Starman v1 package group"

inherit packagegroup

RDEPENDS:${PN} = "\
  starman-ac \
  starman-cc \
  starman-cm \
  starman-pc \
  starman-ui \
"
