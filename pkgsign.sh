#!/bin/sh

SEC_KEY="$1"
VERSION=$(awk '/VERSION/ { print $3; exit }' config.mk)

# Create a full sig file so we can have all releases in it.
sha256sum --tag crowm-"${VERSION}".tar.xz > SHA256
signify -S -s "${SEC_KEY}" -m SHA256 -x crowm-"${VERSION}".tar.xz.sig
cat SHA256 >> crowm-"${VERSION}".tar.xz.sig

# Verify for good measure
signify -C -p lecorbeau.pub -x crowm-"${VERSION}".tar.xz.sig
