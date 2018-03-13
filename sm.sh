#!/bin/bash

function sm_relu() {
    if [[ $1 -le 0 ]]; then echo "1"; else echo $1; fi
}

function sm_linenum() {
    perl -wlne 'print $1 if /(\d+)/'
}

function sm_range() {
    cat $1 | sed -n $(sm_relu $2),$(sm_relu ${3})p
}

function sm_backwardlines() {
    sm_range $1 $(($2-${sm_n_line:-10})) $2
}

function sm_reverse() {
    sed -n '1!G;h;$p'
}

function sm_filename() {
    perl -wlne 'print $4 . "\n" if /^(\s*)(\d*)(\s*)([^:]*)$/' | head -n1
}

function sm() {
    export smtmp=`mktemp` && cat $(sm_backwardlines $smtmp `pt -S --group "$@" | cat -n | tee $smtmp | percol | sm_linenum` | sm_reverse | sm_filename)
}

function vism() {
    export smtmp=`mktemp` && $EDITOR $(sm_backwardlines $smtmp `pt -S --group "$@" | cat -n | tee $smtmp | percol | sm_linenum` | sm_reverse | sm_filename)
}
