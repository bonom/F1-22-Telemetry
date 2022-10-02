@ECHO off

cls
del /f /s /q Outputs\tmp
del start.exe
g++ .\capture\main.cpp -l jsoncpp -Wall -std=c++23 -lws2_32 -o start.exe
.\start.exe 