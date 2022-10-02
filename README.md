# F1-22-Telemetry
This script is written for fun and for improving C++ skills.

## Requirements
The script requires:
- C++23 (C++17 should be enough but is not tested yet)
- Jsoncpp [Link](https://github.com/open-source-parsers/jsoncpp)

It is fully tested on Windows and MacOS (Intel).

## How to use
```shell
git clone https://github.com/bonom/F1-22-Telemetry
cd F1-22-Telemetry
```

In the project there are 3 files that you can use to run the script by just calling one of them depending on the OS you are using.

### Windows
```shell
start.bat
```
Windows make support may come in future.

### MacOS - Linux
```shell
./start.sh
```
or
```shell
make build
make run
```

## Description
The script is written in C++23 and uses Jsoncpp library to parse the data from the game. It will open a socket and listen for data from the game. The data is then parsed and saved in `*.json` files. Every header file has a `*.json` file with the same name that contains the data structure of the header file (e.g. `Telemetry.h` -> `Telemetry.json`). Data are stored in a `tmp` folder until session ends or the script is stopped by Ctrl+C, after that the folder is renamed to `session_track`. For all the output files the structure is a list of dictionaries. The dictionary contains the data for a single packet. The list contains all the packets for a single session and are ordered by frame. Notice that `Data.json` is a huge file where all data are combined together. The other files are more readable and easier to use.

## Future Work
- [ ] Add Python analysis script (e.g. lap time analysis)
- [ ] Add Graphs visualization
- [ ] Add Realtime visualization
- [ ] More...
