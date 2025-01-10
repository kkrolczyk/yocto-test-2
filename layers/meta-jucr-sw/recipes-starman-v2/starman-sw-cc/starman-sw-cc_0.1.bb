SUMMARY = "starman cc recipe summary"
DESCRIPTION = "starman cc recipe description"
LICENSE = "MIT"

python do_display_banner() {
    bb.plain("***********************************************");
    bb.plain("*                                             *");
    bb.plain("*  STARMAN EXAMPLE CC recipe                  *");
    bb.plain("*                                             *");
    bb.plain("***********************************************");
}

addtask display_banner before do_build
