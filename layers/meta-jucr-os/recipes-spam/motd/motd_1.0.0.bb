DESCRIPTION = "Create MOTD with JUCR ASCII text"
LICENSE = "CLOSED"

SRC_URI += "file://motd"

do_install() {
    install -Dm 0644 ${WORKDIR}/motd ${D}${sysconfdir}/motd
    echo "# Built:" $(date "+%Y-%m-%d, %H:%M:%S") on $(hostname) >> ${D}${sysconfdir}/motd
}

FILES_${PN} = "${sysconfdir}/motd"
