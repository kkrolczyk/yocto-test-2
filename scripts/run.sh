#!/bin/bash


case "$1" in
	0)
		printf "typical poky \n"
		cd upstream/poky && source oe-init-build-env ../../build && bitbake core-image-minimal
		;;
	1)
		# NXP 'setup' uses more or less
		# setup-environment => imx-setup-release -> . sources/meta-imx/tools/setup-utils.sh
		# fsl-imx-xwayland, fsl-imx
		# hook_in_layer meta-imx/meta-imx-bsp
		# hook_in_layer meta-imx/meta-imx-sdk
		# hook_in_layer meta-imx/meta-imx-ml
		# hook_in_layer meta-imx/meta-imx-v2x

		printf "jucr from inside the repo \n"
		source layers/oe-init-build-env build && bitbake-layers show-layers && bitbake-layers show-recipes | grep "star\|jucr"
		echo "&& bitbake jucr-minimal"
		bash

		;;
	2)
		printf "jucr from outside the repo \n"
		source layers/meta-jucr/oe-init-build-env build && bitbake jucr-minimal
		;;
	*)
		printf "TODO HELP..... 0=use poky template,  1 use meta-jucr template   2 meta template from upper dir"
		;;
esac

