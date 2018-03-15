#!/bin/bash

function sm_relu() {
    if [[ $1 -le 0 ]]; then echo "1"; else echo $1; fi
}

function sm_linenum() {
    perl -wlne 'print $1 if /(\d+)/'
}

function sm_range() {
    cat "$1" | sed -n $(sm_relu $2),$(sm_relu $3)p
}

function sm_backwardlines() {
    sm_range "$1" $(($2-${sm_n_line:-50})) $2
}

function sm_reverse() {
    sed -n '1!G;h;$p'
}

function sm_filename() {
    perl -wlne 'print $4 . "\n" if /^(\s*)(\d*)(\s*)([^:]*)$/' | head -n1
}

function sm_usage() {
    echo "Usage:\n\tsm <keyword>\t\t\t(search in current working directory/在当前所在目录搜索)\n\tq <keyword>\t\t\t(search in this folder/在本目录搜索)"
}

function sm_guard() {
    if [ -z $1 ]; then sm_usage; false; else true; fi
}

function sm_clip() {
    (pbcopy || xclip -selection primary)
}

function sm() {
    sm_guard $1 && export smtmp=`mktemp` && \
        cat "$(sm_backwardlines $smtmp `pt -S --group "$@" | cat -n | tee $smtmp | percol | sm_linenum` | sm_reverse | sm_filename)" | \
        pt -S -C ${sm_n_line:-50} "$@"
}

function csm() {
    sm_guard $1 && export smtmp=`mktemp` && \
        cat "$(sm_backwardlines $smtmp `pt -S --group "$@" | cat -n | tee $smtmp | percol | sm_linenum` | sm_reverse | sm_filename)" | \
        sm_clip
}

function vism() {
    sm_guard $1 && export smtmp=`mktemp` && \
        ${EDITOR:-vi} "$(sm_backwardlines $smtmp `pt -S --group "$@" | cat -n | tee $smtmp | percol | sm_linenum` | sm_reverse | sm_filename)"
}

export sm_dir=`pwd`
function q() { (cd "$sm_dir"; sm $@) }
function cq() { (cd "$sm_dir"; csm $@) }
function viq() { (cd "$sm_dir"; vism $@) }
