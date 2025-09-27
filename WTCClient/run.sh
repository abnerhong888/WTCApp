#!/bin/bash 

stdbuf -o0 ./build/bin/a.out |& tee run.log
