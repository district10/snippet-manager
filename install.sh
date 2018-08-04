#!/bin/bash

if [ `whoami` = "root" ]; then
    SUDO=""
else
    SUDO="sudo"
fi

PT_URL="https://github.com/monochromegane/the_platinum_searcher/releases/download/v2.1.6/pt_linux_amd64.tar.gz"

function install_curl() { $SUDO apt-get install -y curl; }
function install_wget() { $SUDO apt-get install -y wget; }
function install_pt() { cd /tmp && curl -L -o pt_linux_amd64.tar.gz "$PT_URL" && tar zxvf pt_linux_amd64.tar.gz && $SUDO cp pt_linux_amd64/pt /bin; }
function install_python() { $SUDO apt-get install -y python-dev; }
function install_pip() { wget https://bootstrap.pypa.io/get-pip.py -O - | python; }
function install_percol() { pip install percol; }

case "$(uname -s)" in
    Darwin)
        echo 'Mac OS X'
        brew install pt
        pip install percol
        echo "Installation Done"
    ;;
    Linux)
        echo 'Linux'
        curl --version 2&>/dev/null || install_curl
        wget --version 2&>/dev/null || install_wget
        pt --version 2&>/dev/null || install_pt
        python --version 2&>/dev/null || install_python
        pip --version 2&>/dev/null || install_pip
        percol --version 2&>/dev/null || install_percol
        echo "Installation Done"
    ;;

    *)
        echo 'Not Linux nor macOS? You man need to manually install pt and percol'
    ;;
esac
