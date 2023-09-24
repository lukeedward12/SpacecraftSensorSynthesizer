# SpacecraftSensorSynthesizer
SpacecraftSensorSynthesizer (S3) is a real-time sensor data processing module for processing spacecraft sensor readings, performing numerical analysis, and reporting to a debug output. 

## Requirements
* Docker
* apt package manager

## Build & Test
All building and unit testing is handled with CMake and CTest in a Docker container to prevent conflicts with dev environment packages. \
To build and test: \
    `. ./build_test.sh`