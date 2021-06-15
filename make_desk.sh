#!/bin/sh

make clean; 

USE_POLYMOST=1 \
WITHOUT_GTK=1 \
USE_OPENGL=USE_GLES2 \
USE_ASM=0 \
GAME=freelancer \
GAMEDATA=freelancer-data \
make 
