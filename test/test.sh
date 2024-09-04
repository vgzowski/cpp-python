#!bin/bash
# sudo rm -rf build
mkdir -p build
cd build
cmake ..
cmake --build .
cmake --build . --target run_all_tests
cd ..
# sudo rm -rf build