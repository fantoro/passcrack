#!/bin/bash
g++ -lcrypto -ggdb -o passcrack main.cpp classes/*.cpp classes/passlist/*.cpp
