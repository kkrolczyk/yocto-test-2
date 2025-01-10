# https://docs.yoctoproject.org/5.0.5/ref-manual/features.html#ref-features-image

# those are not features, and likely should be a separate files in includes
# this might be also a part of "-base" image



# TODO
IMAGE_INSTALL = "packagegroup-core-boot ${CORE_IMAGE_EXTRA_INSTALL}"



INHERIT += " buildhistory"
