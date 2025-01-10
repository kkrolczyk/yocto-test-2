SUMMARY = "temporary spam recipe "
DESCRIPTION = "TEMPORARY SPAM RECIPE"
LICENSE = "MIT"

python do_display_banner() {
    bb.plain("***********************************************");
    bb.plain("*                                             *");
    bb.plain("*  TEMPORARY SPAM RECIPE                      *");
    bb.plain("*                                             *");
    bb.plain("***********************************************");
}

addtask display_banner before do_build
