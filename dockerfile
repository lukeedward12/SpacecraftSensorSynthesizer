FROM ubuntu:22.04

# Update and install necessary packages
RUN apt-get update && apt-get install -y \
    g++ \
    cmake \
    make

# Set the working directory in the Docker container
WORKDIR /SpacecraftSensorSynthesizer

# Copy your source code into the Docker container
#COPY . /app

# Build your C++ project using CMake
CMD rm -rf build && mkdir build && cd build && cmake .. && make clean && make && ctest

# Set the default command for the container to your executable