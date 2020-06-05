#!/usr/bin/env bash

COMPILER="g++"
CPP_ARGS="-std=c++11 -fdiagnostics-color=always"
source args.sh
CPP_ARGS="$CUSTOM_CPP_ARGS $CPP_ARGS"
NOCOLOR=0
if [ ! "$NO_COLOR" == "" ]
then
  NOCOLOR=1
fi

if [ "$EXECUTABLE_NAME" == "" ]
then
  EXECUTABLE_NAME="program.lexe"
fi

COMPILE=1
GENERATE=1

if [ "$1" == "release" ]
then
  CPP_ARGS="-O3 $CPP_ARGS"
elif [ "$1" == "debug" ]
then
  CPP_ARGS="-g $CPP_ARGS"
else
  if [ $NOCOLOR -eq 0 ]
  then
    echo -n "❌ "
  fi
  echo "Pass either debug or release as the first parameter"
  exit 1
fi

if [ "$2" == "--gen-only" ] || [ "$2" == "-g" ]
then
  COMPILE=0
elif [ "$2" == "--compile-only" ] || [ "$2" == "-c" ]
then
  GENERATE=0
fi

if [ $GENERATE -eq 1 ]
then
  echo -n "" > compile_commands.json
  echo "[" >> compile_commands.json
fi

if [ $COMPILE -eq 1 ]
then
  if [ ! -d obj ]
  then
    mkdir obj
  fi

  if [ ! -d out ]
  then
    mkdir out
  fi
fi

FIRST_FILE=1

for SRCFILE in src/*.cpp
do
  SRCFILENAME="$(basename $SRCFILE .cpp)"
  COMPILE_COMMAND="$COMPILER $CPP_ARGS -c src/$SRCFILENAME.cpp -o obj/$SRCFILENAME.o"

  if [ $COMPILE -eq 1 ]
  then
    echo -n "Compiling $SRCFILE..."
    eval "$COMPILE_COMMAND" 2>/tmp/Error
    ERR=$?
    if [ $ERR -ne 0 ]
    then
      if [ $NOCOLOR -eq 0 ]
      then
        echo " ❌"
      else
        echo ""
      fi
      cat /tmp/Error >&2
      echo "Error while compiling: $COMPILE_COMMAND"
      exit $ERR
    elif [ $NOCOLOR -eq 0 ]
    then
      echo " ✔️"
    fi
  fi

  if [ $FIRST_FILE -eq 1 ]
  then
    FIRST_FILE=0
  else
    if [ $GENERATE -eq 1 ]
    then
      echo "," >> compile_commands.json
    fi
  fi

  if [ $GENERATE -eq 1 ]
  then
    echo "  {" >> compile_commands.json
    echo "    \"directory\": \"$(pwd)\"," >> compile_commands.json
    echo "    \"file\": \"src/$SRCFILENAME.cpp\"," >> compile_commands.json
    echo "    \"output\": \"out/$SRCFILENAME.o\"," >> compile_commands.json
    echo "    \"command\": \"$COMPILE_COMMAND\"" >> compile_commands.json
    echo -n "  }" >> compile_commands.json
  fi
done

if [ $FIRST_FILE -eq 1 ]
then
  if [ $NOCOLOR -eq 0 ]
  then
    echo -n "❌ "
  fi
  echo "No .cpp files in src"
  exit 1
fi

LINK_FILES=""
for TO_LINK in obj/*.o
do
  LINK_FILES="$TO_LINK $LINK_FILES"
done

LINK_COMMAND="$COMPILER $CPP_ARGS $LINK_FILES -o out/$EXECUTABLE_NAME"

if [ $COMPILE -eq 1 ]
then
  eval $LINK_COMMAND 2>/tmp/Error

  ERR=$?
  if [ $ERR -ne 0 ]
  then
    cat /tmp/Error >&2
    echo "Error while linking: $LINK_COMMAND"
    exit $ERR
  fi

  echo ""
  echo "Created executable out/$EXECUTABLE_NAME"
fi

# if [ $GENERATE -eq 1 ]
# then
#   echo "," >> compile_commands.json
#   echo "  {" >> compile_commands.json
#   echo "    \"directory\": \"$(pwd)\"," >> compile_commands.json
#   echo "    \"file\": \"src/$SRCFILENAME.cpp\"," >> compile_commands.json
#   echo "    \"output\": \"out/$SRCFILENAME.o\"," >> compile_commands.json
#   echo "    \"command\": \"$COMPILE_COMMAND\"" >> compile_commands.json
#   echo -n "  }" >> compile_commands.json
# fi

if [ $GENERATE -eq 1 ]
then
  echo "" >> compile_commands.json
  echo "]" >> compile_commands.json
fi