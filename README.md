# Jucr Manifest for Yocto building JUCR-OS

## Contents

This repository consists of:

```
.
├── default.xml                                 # main manifest. Later also: `pinned.xml`
├── docs                                        # intended to keep more detailed info
├── layers
│   ├── conf                                    # TODO: temporary, switch to TEMPLATE_CONF
│   ├── meta-jucr-hw                            # layer keeping hardware specific configs, MACHINE
│   ├── meta-jucr-os                            # layer keeping DISTRO and recipes for u-boot bootloader, and device-tree files
│   ├── meta-jucr-sw                            # layer with all software components developed privately by JUCR
│   └── oe-init-build-env                       # populates build dir with config
├
├── README.md                                   # this file
├── scripts
│   ├── bootstrap.sh                            # shell script populating repositories (alternative to google's repo)
│   ├── pin_versions.sh                         # shell script used to run builds
│   └── run.sh                                  # shell script used to establish baseline revisions
├
├── upstream                                    # dir keeping layer collection with all software components downloaded from upstream sources
└── upstream-modifications                      # collection of patches/appends for upstream layers, which haven't been upstreamed
```

As of now - no support for docker is considered.

## Workflow idea

0. install google repo:
1. clone this repo

	a. if using google repo: `repo init -u ssh://git@github.com/jucros-manifest -b main`   # preferred, see (`docs/why_repo.md`)
	b. if cloning using git: `git clone https://github.com/jucros-manifest`

3. run bootstrap.sh  # `./scripts/bootstrap.sh` - setup host & clone upstream repos & checkout upstream branches/tags
4. run run.sh        # `./run.sh` - creates (or reuses) build dir (if dest contains "conf", otherwise creates one) & builds target

## Info

Layers pulled usually contain more than needed.
TODO: either we'll just copy needed recipes to jucr layers, or keep them as they are, and just use what we need

Ideally, we can produce images:
- for qemu running on developer's host, emulating aarch64 production/testing image
- production used for flashing

## Rules

- Never modify stuff in `upstream` - all modifications either directly upstreamed, or kept in `upstream-modifications`

## Notices

Yocto is sensitive to many params, including host's machine Ubuntu version, host gcc or other tools version, whether the disk is encrypted or not, which Yocto version is used (some build only on specific Ubuntu's) ect.

- Yocto "scarthgap" was choosen, currently (2024-12) 5.0.5

- for Yocto's sscache - `pip install websockets`
