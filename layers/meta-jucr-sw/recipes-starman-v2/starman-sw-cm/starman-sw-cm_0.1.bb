SUMMARY = "starman cm recipe summary"
DESCRIPTION = "starman cm recipe description"
LICENSE = "MIT"

python do_display_banner() {
    bb.plain("***********************************************");
    bb.plain("*                                             *");
    bb.plain("*  Example starman CM recipe                  *");
    bb.plain("*                                             *");
    bb.plain("***********************************************");
}

addtask display_banner before do_build
