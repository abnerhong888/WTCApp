#!/bin/bash


build_resources(){
    glib-compile-resources $1 \
        --generate-source \
        --target=resources.c 

    glib-compile-resources $1 \
        --generate-header \
        --target=resources.h 
}

build_resources wtc.gresource.xml