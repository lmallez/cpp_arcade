#!/usr/bin/env bash

cd cmake-build-debug
make GRAPHIC_Caca
make GRAPHIC_SFML
make GAME_BasicGame
cd ..
cp cmake-build-debug/libGRAPHIC_*.so ./graphics
cp cmake-build-debug/libGAME_*.so ./games