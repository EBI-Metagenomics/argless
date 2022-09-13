#!/bin/bash

function display_usage {
    echo "./meld.sh hdr|src FILES"
}

type=$1
shift

if [ "$type" != "hdr" ] && [ "$type" != "src" ]; then
    display_usage
fi

files=$*
{
    if [ "$type" == "hdr" ]; then
        echo "#ifndef ARGLESS_H"
        echo "#define ARGLESS_H"
    else
        echo "#include \"argless.h\""
    fi
    echo

    for file in $files; do
        display=0

        while IFS="" read -r p || [ -n "$p" ]; do
            [[ "$p" =~ meld-cut-here ]] && display=$((display ^= 1)) && continue
            [ $display == 1 ] && printf '%s\n' "$p" | sed 's/extern/static/'
        done <"$file"

        echo
    done

    if [ "$type" == "hdr" ]; then echo "#endif"; fi
} | clang-format -style=file
