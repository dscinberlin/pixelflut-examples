#!/bin/bash

exec 3</dev/tcp/35.234.105.190/1234

set_pixel()
{
    echo "CC $@" 1>&3
}

for x in {0..1919}; do
    for y in {0..1079}; do
        set_pixel $x $y FF0000
    done
done