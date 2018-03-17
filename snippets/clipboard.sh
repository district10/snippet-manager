function clipcopy() {
  emulate -L zsh
  local file=$1
  if [[ $OSTYPE == darwin* ]]; then
    if [[ -z $file ]]; then
      pbcopy
    else
      cat $file | pbcopy
    fi
  elif [[ $OSTYPE == cygwin* ]]; then
    if [[ -z $file ]]; then
      cat > /dev/clipboard
    else
      cat $file > /dev/clipboard
    fi
  else
    which xclip &>/dev/null
    if [[ $? != 0 ]]; then
      print "clipcopy: Platform $OSTYPE not supported or xclip not installed" >&2
      return 1
    fi
    if [[ -z $file ]]; then
      xclip -in -selection clipboard
    else
      xclip -in -selection clipboard $file
    fi
  fi
}

function clippaste() {
  emulate -L zsh
  if [[ $OSTYPE == darwin* ]]; then
    pbpaste
  elif [[ $OSTYPE == cygwin* ]]; then
    cat /dev/clipboard
  else
    which xclip &>/dev/null
    if [[ $? != 0 ]]; then
      print "clipcopy: Platform $OSTYPE not supported or xclip not installed" >&2
      return 1
    fi
    xclip -out -selection clipboard
  fi
}
