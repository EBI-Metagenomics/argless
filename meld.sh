#!/bin/bash

function display_usage {
    echo "./meld.sh hdr|src|proto FILES"
}

type=$1
shift

if [ "$type" != "hdr" ] && [ "$type" != "src" ] && [ "$type" != "proto" ]; then
    display_usage
fi

if [ "$type" == "proto" ]; then
    cut=meld-cut-proto
else
    cut=meld-cut-here
fi

files=$*
{
    if [ "$type" == "hdr" ]; then
        echo "#ifndef ARGLESS_H"
        echo "#define ARGLESS_H"
    elif [ "$type" == "proto" ]; then
        echo "#include \"argless.h\""
    fi
    echo

    for file in $files; do
        display=0

        while IFS="" read -r p || [ -n "$p" ]; do
            [[ "$p" =~ $cut ]] && display=$((display ^= 1)) && continue
            [ $display == 1 ] && printf '%s\n' "$p" | sed -E 's/^([a-z].*(al_|help_|opts_|opt_|argvec_|echo|arg_)[a-z0-9_]*\(.*)$/static \1/' | sed 's/static static/static/g'
        done <"$file"

        echo
    done

    if [ "$type" == "hdr" ]; then echo "#endif"; fi
} | clang-format -style=file
