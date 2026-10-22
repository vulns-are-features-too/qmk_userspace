#!/usr/bin/env bash
# Check the device has gone into its BOOT state and is ready to be mounted.
#
# The mount point and source should be in /etc/fstab
# For example:
# /dev/sdb1 /media/<USER> auto rw,noauto,user 0 0
#
# Multiple entries for the same mount point not handled for now.

set -euo pipefail

mount_point="/media/$USER"
if ! findmnt --fstab --target "$mount_point" &>/dev/null; then
    echo 'Mount not in /etc/fstab'
    exit 1
fi

mount_src="$(findmnt --fstab --target "/media/$USER" -n | cut -d' ' -f2)"

if [[ ! -b "$mount_src" ]]; then
    echo "Waiting for $mount_src"
    echo "Press BOOT key"
    while [[ ! -b "$mount_src" ]]; do
        sleep 0.5
    done
fi
