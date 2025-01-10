#!/bin/bash

STATIC_MANIFEST=pinned.xml
repo manifest -r -o $TATIC_MANIFEST && \
git add pinned.xml && \
git commit -m "pinned: build from $(date +'%Y-%m-%d')" && \
git push
