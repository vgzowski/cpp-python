cmake_minimum_required(VERSION 3.10)

project(CppPythonLibrary VERSION 1.0 LANGUAGES CXX)

# Specify the C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Create header-only interface libraries for each namespace
add_library(cpp_python INTERFACE)
add_library(cpp_python_concepts INTERFACE)
add_library(cpp_python_type_traits INTERFACE)

# Set include directories for each library
target_include_directories(cpp_python INTERFACE ${CMAKE_SOURCE_DIR}/cpp_python)
target_include_directories(cpp_python_concepts INTERFACE ${CMAKE_SOURCE_DIR}/cpp_python_concepts)
target_include_directories(cpp_python_type_traits INTERFACE ${CMAKE_SOURCE_DIR}/cpp_python_type_traits)

# Optionally: install rules
include(GNUInstallDirs)

install(DIRECTORY cpp_python/
        DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}/
        FILES_MATCHING PATTERN "*.h")

install(DIRECTORY cpp_python_concepts/
        DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}/cpp_python_concepts
        FILES_MATCHING PATTERN "*.h")

install(DIRECTORY cpp_python_type_traits/
        DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}/cpp_python_type_traits
        FILES_MATCHING PATTERN "*.h")

# # Install the umbrella header
# install(FILES cpp_python/cpp_python.h
#         DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}/cpp_python)
