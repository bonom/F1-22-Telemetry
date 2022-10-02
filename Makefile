COMPILER = g++
CFLAGS = -Wall -g -std=c++23
TARGET = capture/main.cpp
OUT = go
JSONINCLUDE = /usr/local/Cellar/jsoncpp/1.9.5/include
JSONLIB = jsoncpp

.PHONY: help build run clean

help:
	@echo "\n--------------------------------------------------\n"
	@echo "make build	[ build the script ]"
	@echo "make run	[ run the script ]"
	@echo "make clean	[ clean tmp folder ]"
	@echo "make help	[ show this help and the README.md ]\n"
	@echo "--------------------------------------------------\n"


build:
	@echo "Building script..."
	@$(COMPILER) $(CFLAGS) $(TARGET) -I $(JSONINCLUDE) -l $(JSONLIB) -o $(OUT)
	@echo "Build done."

clean:
	@rm $(OUT)
	@echo "Clean done."

run:
	@clear
	@./go
