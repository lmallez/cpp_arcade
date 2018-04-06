#!/usr/bin/env bash

cd cmake-build-debug
make GRAPHIC_Caca -j4
make GRAPHIC_SFML -j4
make GRAPHIC_SDL -j4
make GAME_BasicGame -j4
make GAME_SNAKE -j4
make GAME_SOLAR_FOX -j4
cd ..
cp cmake-build-debug/libGRAPHIC_SFML.so ./graphics
cp cmake-build-debug/libGRAPHIC_SDL.so ./graphics
cp cmake-build-debug/libGRAPHIC_Caca.so ./graphics
cp cmake-build-debug/libGAME_BasicGame.so ./games
cp cmake-build-debug/libGAME_BasicGame.so ./games
cp cmake-build-debug/libGAME_SNAKE.so ./games
cp cmake-build-debug/libGAME_SOLAR_FOX.so ./games
