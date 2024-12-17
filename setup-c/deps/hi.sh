#!/bin/bash
#
if [[ $(uname -v | grep Debian) ]]; then
  echo deb
else
  echo works
fi

