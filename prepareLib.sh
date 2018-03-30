#!/usr/bin/env bash

cd cmake-build-debug
make GRAPHIC_Caca -j4
make GRAPHIC_SFML -j4
make GAME_BasicGame -j4
cd ..
cp cmake-build-debug/libGRAPHIC_SFML.so ./graphics
cp cmake-build-debug/libGRAPHIC_Caca.so ./graphics
cp cmake-build-debug/libGAME_BasicGame.so ./games
