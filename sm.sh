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
    perl -wlne '(print $4 and last) if /^(\s*)(\d*)(\s*)([^:]*)$/'
}

function sm_usage() {
    echo 'Usages:
        q   <keyword>           # search snippet
        cq  <keyword>           # search snippet, copy to clipboard
        nq  <keyword>           # new (create) a snippet
        lq  <keyword>           # list all snippets
        viq <keyword>           # edit matched snippet
    '
}

function sm_guard() {
    if [ -z $1 ]; then sm_usage; false; else true; fi
}

function sm_clip() {
    xclip -selection clipboard
}

export sm_grep_tool=`(pt --version &> /dev/null && echo "pt") || (ag --version &>/dev/null && echo "ag")`
export sm_filter_tool=`(percol --version &> /dev/null && echo "percol") || (fzf --version &>/dev/null && echo "fzf")`

function update_sm_filter_opts() {
    if [ $sm_filter_tool="fzf" ]; then
        opts="--reverse --no-sort"
    else
        opts=""
    fi
}

function sm_grep() {
    $sm_grep_tool "$@"
}

function sm_filter() {
    $sm_filter_tool "$@"
}

function sm() {
    sm_guard $1 && export smtmp=`mktemp` && \
        cat "$(sm_backwardlines $smtmp `sm_grep -S --group "$@" | cat -n | tee $smtmp | sm_filter --query="$@" | sm_linenum` | sm_reverse | sm_filename)" | \
        sm_grep -S -C ${sm_n_line:-50} "$@"
}

function csm() {
    sm_guard $1 && export smtmp=`mktemp` && \
        cat "$(sm_backwardlines $smtmp `sm_grep -S --group "$@" | cat -n | tee $smtmp | sm_filter --query="$@" | sm_linenum` | sm_reverse | sm_filename)" | \
        sm_clip
}

function vism() {
    sm_guard $1 && export smtmp=`mktemp` && \
        ${EDITOR:-vi} "$(sm_backwardlines $smtmp `sm_grep -S --group "$@" | cat -n | tee $smtmp | sm_filter --query="$@" | sm_linenum` | sm_reverse | sm_filename)"
}

export sm_dir="`dirname "$0"`"
export sm_n_line="500"
function q() { (cd "$sm_dir"; sm $@) }
function cq() { (cd "$sm_dir"; csm $@) }
function nq() { ${EDITOR:-vi} "$sm_dir/snippets/$1" }
function lq() { ${EDITOR:-vi} `find $sm_dir -type f \( -iname "*.*" ! -path "*/.*" \) | sm_filter` }
function viq() { (cd "$sm_dir"; vism $@) }
