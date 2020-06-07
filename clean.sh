#!/usr/bin/env bash

NOCOLOR=0
# shellcheck disable=SC2153
if [ ! "$NO_COLOR" == "" ]
then
  NOCOLOR=1
fi

# CHECKMARK_SYMBOL="✔️"
# CROSS_SYMBOL="❌"

CHECKMARK_SYMBOL="✓"
CROSS_SYMBOL="❌"

if [ $NOCOLOR -eq 0 ]
then
  GREEN_COLOR_ANSI="\0033[32m"
  RED_COLOR_ANSI="\0033[31m"
  STOP_COLOR_ANSI="\0033[39m"

  CHECKMARK_SYMBOL="$GREEN_COLOR_ANSI$CHECKMARK_SYMBOL$STOP_COLOR_ANSI"
  CROSS_SYMBOL="$RED_COLOR_ANSI$CROSS_SYMBOL$STOP_COLOR_ANSI"
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
      echo -e " $CROSS_SYMBOL"
    else
      echo ""
    fi
    echo "An error occured!"
    exit $ERR
  elif [ $NOCOLOR -eq 0 ]
  then
    echo -e " $CHECKMARK_SYMBOL"
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
      echo -e " $CROSS_SYMBOL"
    else
      echo ""
    fi
    echo "An error occured!"
    exit $ERR
  elif [ $NOCOLOR -eq 0 ]
  then
    echo -e " $CHECKMARK_SYMBOL"
  fi
fi