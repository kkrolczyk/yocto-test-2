SUMMARY = "starman ui recipe summary"
DESCRIPTION = "starman ui recipe description"
LICENSE = "MIT"

python do_display_banner() {
    bb.plain("***********************************************");
    bb.plain("*                                             *");
    bb.plain("*  STARMAN UI    recipe                       *");
    bb.plain("*                                             *");
    bb.plain("***********************************************");
}

addtask display_banner before do_build
