#!/bin/sh

sudo apt-get update && sudo apt-get upgrade
sudo apt-get install libusb-1.0-0-dev pkg-config
sudo apt-get install libglfw3-dev

git clone https://github.com/IntelRealSense/librealsense.git
cd librealsense
git checkout tags/v1.12.1
mkdir build
cd build

cmake .. -DBUILD_EXAMPLES:BOOL=true
make && sudo make install
sudo ldconfig
