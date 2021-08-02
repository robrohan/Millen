#!/bin/sh

GAME=freelancer

make clean GAME=${GAME} GAMEDATA=${GAME}-data; 

make USE_POLYMOST=1 \
  WITHOUT_GTK=1 \
  USE_OPENGL=USE_GLES2 \
  USE_ASM=0 \
  GAME=freelancer \
  GAMEDATA=freelancer-data \
  PRELOAD="../freelancer/hive@/home/web_user/.${GAME}" \
  CC=emcc \
  CXX=emcc \
  AR=emar
