#!/bin/bash

function relu() {
    if [[ $1 -le 0 ]]; then echo "1"; else echo $1; fi;
}

function linenum() {
    perl -wlne 'print $1 if /(\d+)/'
}

function range() {
    cat $1 | sed -n $(relu $2),$(relu ${3})p
}

function backward30line() {
    range $1 $(($2-10)) $2
}

function reverse() {
    sed -n '1!G;h;$p' -
}

function sm() {
    export smtmp=`mktemp` && backward30line $smtmp `pt --group $@ | cat -n | tee $smtmp | percol | linenum`
}
