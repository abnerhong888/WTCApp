#!/bin/bash

rm CMakePresets.json -f
ln -s ../CMakePresets.json CMakePresets.json

mkdir -p build

cd build

rm * -rf

stdbuf -o0 cmake --preset=unix .. |& tee cmake.log

stdbuf -o0 cmake --build . |& tee build.log
