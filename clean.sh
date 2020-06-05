#!/usr/bin/env bash

NOCOLOR=0
# shellcheck disable=SC2153
if [ ! "$NO_COLOR" == "" ]
then
  NOCOLOR=1
fi

if [ -d obj ]
then
  echo -n "Removing obj..."
  rm -rf obj

  ERR=$?
  if [ $ERR -ne 0 ]
  then
    if [ $NOCOLOR -eq 0 ]
    then
      echo " ❌"
    else
      echo ""
    fi
    echo "An error occured!"
    exit $ERR
  elif [ $NOCOLOR -eq 0 ]
  then
    echo " ✔️"
  fi
fi

if [ -d out ]
then
  echo -n "Removing out..."
  rm -rf out

  ERR=$?
  if [ $ERR -ne 0 ]
  then
    if [ $NOCOLOR -eq 0 ]
    then
      echo " ❌"
    else
      echo ""
    fi
    echo "An error occured!"
    exit $ERR
  elif [ $NOCOLOR -eq 0 ]
  then
    echo " ✔️"
  fi
fi