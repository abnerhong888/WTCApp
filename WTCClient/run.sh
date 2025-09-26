#!/bin/bash 

stdbuf -o0 ./build/a.out |& tee run.log
