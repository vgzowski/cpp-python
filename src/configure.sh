#!bin/bash
sudo rm -rf build/
mkdir build
cd build
cmake ..
cmake --build .
sudo cmake --install .
cd ..
sudo rm -rf build/