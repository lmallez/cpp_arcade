#!/usr/bin/env bash

cd cmake-build-debug
make _arcade_sfml -j4
make _arcade_sdl -j4
make _arcade_caca -j4
make _arcade_basic_game -j4
make _arcade_nibbler -j4
make _arcade_solarfox -j4
make _arcade_wolf3D -j4
cd ..
cp cmake-build-debug/lib_arcade_sfml.so ./graphics
cp cmake-build-debug/lib_arcade_sdl.so ./graphics
cp cmake-build-debug/lib_arcade_caca.so ./graphics
cp cmake-build-debug/lib_arcade_basic_game.so ./games
cp cmake-build-debug/lib_arcade_nibbler.so ./games
cp cmake-build-debug/lib_arcade_solarfox.so ./games
cp cmake-build-debug/lib_arcade_wolf3D.so ./games

