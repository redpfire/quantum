#!/bin/bash

mkdir -p qmk_firmware/keyboards/3w6/keymaps/aika

cp config.h qmk_firmware/keyboards/3w6/keymaps/aika/
qmk json2c keymap.json -o qmk_firmware/keyboards/3w6/keymaps/aika/keymap.c

pushd qmk_firmware/keyboards/3w6/keymaps/aika
qmk flash -kb 3w6/rev3 -km aika

popd
