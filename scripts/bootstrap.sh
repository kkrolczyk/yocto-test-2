#!/bin/bash

case "$1" in
	0)
		printf "Install required packages\n"
		printf "* for non-debian derevatives follow https://docs.yoctoproject.org/ref-manual/system-requirements.html#required-packages-for-the-build-host\n"
		printf "* sudo apt install git gawk wget git diffstat unzip texinfo gcc build-essential chrpath socat cpio python3 python3-pip python3-pexpect xz-utils debianutils iputils-ping python3-git python3-jinja2 python3-subunit zstd liblz4-tool file locales libacl1 \n"
		;;
	1)
		printf "download required repositories\n"
		repos=( git.openembedded.org/meta-openembedded
			git.yoctoproject.org/poky )

		$(cd upstream && \
		for repo in ${repos[@]}; do git clone --depth 1 --branch scarthgap --single-branch https://$repo; done)
		;;
	2)
		printf "download optional repositories, for example to do an update/sync with upstream\n"
		;;
	3)
		printf "setup cache, use sscache/mirrors (for CI)\n"
		;;
	*)
		printf "USAGE: \n $0 [ 0 | 1 | 2 ]"
		printf "\n 0 - install required yocto host packages"
		printf "\n 1 - download required layers"
		printf "\n 2 - download optional layers, for development"
		printf "\n 3 - TODO - setup cache"
		printf "\n"
		;;
esac
