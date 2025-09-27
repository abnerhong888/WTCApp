#!/bin/bash 

stdbuf -o0 ./build/bin/wtc |& tee run.log
