#!/usr/bin/env bash
# find a keyboard whose parts (/ separated) begins with the provided pattern

set -euo pipefail

if [[ $# -eq 0 ]] || [[ "$1" = "" ]]; then
    pattern="$(jq -r '.build_targets[][0]' qmk.json | fzf --select-1)"
else
    pattern="$1"
fi
jq -r '.build_targets[][0]' qmk.json | grep -P "(^|\/)${pattern}"
