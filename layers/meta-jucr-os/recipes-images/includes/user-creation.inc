# images need to have additional users to run greengrass software + allow ssh login

# extrausers is only for image-recipes, use useradd for recipe bound

inherit extrausers
IMAGE_INSTALL:append = " sudo"
# PASSWD == password
PASSWD = "\$6\$vRcGS0O8nEeug1zJ\$YnRLFm/w1y/JtgGOQRTfm57c1.QVSZfbJEHzzLUAFmwcf6N72tDQ7xlsmhEF.3JdVL9iz75DVnmmtxVnNIFvp0"
USER_UID = "1200"
USER_NAME = "ggc_user"
USER_GROUPS = "sudo"

EXTRA_USERS_PARAMS:append = "\
     useradd -u ${USER_UID} -d /home/${USER_NAME} -s /bin/sh -p '${PASSWD}' ${USER_NAME}; \
     usermod -a -G ${USER_GROUPS} ${USER_NAME}; \
"
