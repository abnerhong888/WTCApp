#!/bin/bash

rm CMakePresets.json -f
ln -s ../CMakePresets.json CMakePresets.json

mkdir -p build

cd build

rm * -rf

stdbuf -oL cmake --preset=unix .. |& tee cmake.log

stdbuf -oL cmake --build . |& tee build.log