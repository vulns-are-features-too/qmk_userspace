keymap := "vaft"
mount_point := x"/media/$USER"

alias b := build
alias f := flash

init:
    sudo mkdir -p {{mount_point}}
    sudo chown "$USER" {{mount_point}}
    qmk setup
    qmk git-submodule
    qmk config user.overlay_dir="$(realpath .)"
    qmk doctor

build keyboard="":
    kb="$(./match_target.sh {{keyboard}})" && make "$kb:{{keymap}}"

flash keyboard="":
    #!/usr/bin/env bash
    set -euo pipefail
    ./wait_device_booting_and_mountable.sh
    mount {{mount_point}}
    kb="$(./match_target.sh {{keyboard}})"
    just build {{keyboard}}
    qmk flash -kb "$kb" -km {{keymap}}
    umount {{mount_point}}
