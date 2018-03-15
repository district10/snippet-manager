#!/usr/bin/env bash

echo "I'm in $(pwd)"
echo "I'm in `pwd`"

if [ -z "$string" ]; then
  echo "String is empty"
elif [ -n "$string" ]; then
  echo "String is not empty"
fi

echo {A,B}.js
