SUMMARY = "starman ac em recipe summary"
DESCRIPTION = "starman ac em recipe description"
LICENSE = "MIT"

python do_display_banner() {
    bb.plain("***********************************************");
    bb.plain("*                                             *");
    bb.plain("*  STARMAN AC EM recipe                       *");
    bb.plain("*                                             *");
    bb.plain("***********************************************");
}

addtask display_banner before do_build
