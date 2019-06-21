#!/usr/bin/bash
cd /home/fantoro/cpp/passcrack
g++ main.cpp -lcrypto -ggdb -o passcrack classes/*.cpp
