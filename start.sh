#!/bin/bash
clear; rm go; rm -rf Outputs/tmp; g++ -std=c++20 capture/main.cpp -o go -Wall -I /usr/local/Cellar/jsoncpp/1.9.5/include -l jsoncpp && ./go
