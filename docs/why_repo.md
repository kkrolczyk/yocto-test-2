# Repo used to control layers

Reason for using "repo" Google tool - hated by many, is to establish baseline.

While one can easily hack a shell script to do git clone of a bunch of repositories, and checkout them to a certain branch - it gets more complicated if we want to checkout just some repositories, and control their checkout's SHA, to guarantee reproducible builds.


Intended usage is as follows:

	repo init -u <path to remote manifest repository> -b main
	repo sync -j4

This looks for `default.xml` file in that git repository, on main branch (by default "master" was used)

Repo init creates `.repo` with git repositories in top-dir, downloads and checks them out (during sync) to top-dir according to manifest.
This allows to manage multiple related git repositories, and pin their SHA.

Repo allows to clone repos from manifest, selecting groups:

	repo init -u <path to remote manifest repository> -b main -g all,imx

see `repo init --help` for details. Current JUCR manifest supports a few groups.