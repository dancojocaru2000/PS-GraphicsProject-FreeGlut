#!/usr/bin/env bash
CUSTOM_CPP_ARGS=""

for ARG in "-lGL" "-lGLU" "-lglut" "-lpthread" "-D=LINUX_PLATFORM"
do
  CUSTOM_CPP_ARGS="$ARG $CUSTOM_CPP_ARGS"
done