SUMMARY = "starman cc cfg recipe summary"
DESCRIPTION = "starman cc cfg recipe description"
LICENSE = "MIT"

python do_display_banner() {
    bb.plain("***********************************************");
    bb.plain("*                                             *");
    bb.plain("*  STARMAN CC cfg recipe                      *");
    bb.plain("*                                             *");
    bb.plain("***********************************************");
}

addtask display_banner before do_build


inherit useradd
USERADD_PACKAGES = "${PN}"
GROUPADD_PARAM:${PN} = "--system systemuser"
# This creates a non-root user that cannot be logged in as
USERADD_PARAM:${PN} = "--system -s /sbin/nologin -g systemuser systemuser"
