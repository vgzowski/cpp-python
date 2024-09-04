cmake_minimum_required(VERSION 3.10)
project(TestProject)

# Set the C++ standard and compiler flags
set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -O2 -Wall -Wextra -fconcepts-diagnostics-depth=20")

# Function to create test targets for a given directory
function(add_test_directory dir)
    # Collect all .cpp files in the directory
    file(GLOB_RECURSE test_files ${dir}/*.cpp)

    # Create an executable for each test file
    foreach(test_file ${test_files})
        # Get the filename without extension and path
        get_filename_component(test_name ${test_file} NAME_WE)

        # Create the executable
        add_executable(${test_name} ${test_file})

        # Add to the list of test executables
        list(APPEND TEST_EXECUTABLES ${test_name})
    endforeach()
endfunction()

# List to store all test executables
set(TEST_EXECUTABLES "")

# Add test directories
add_test_directory(runtime_test)
add_test_directory(static_test)

# Create a custom target to build all tests
add_custom_target(run_all_tests
    COMMAND ${CMAKE_COMMAND} --build .
    DEPENDS ${TEST_EXECUTABLES}
    COMMENT "Building all tests"
)

# Optionally, add each test to CTest if using CTest
foreach(test_executable ${TEST_EXECUTABLES})
    add_test(NAME ${test_executable} COMMAND ${test_executable})
endforeach()
