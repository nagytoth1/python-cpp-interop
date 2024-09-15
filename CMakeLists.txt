cmake_minimum_required(VERSION 3.5...3.18)
project(PybindExample)

set(Python3_EXECUTABLE "/mnt/c/repo/python-cpp-call/venv/bin/python3.12") # Update this to the actual path of python3.12

find_package(Python3 COMPONENTS Interpreter Development REQUIRED)

execute_process(
    COMMAND ${Python3_EXECUTABLE} -m pybind11 --cmakedir
    OUTPUT_VARIABLE PYBIND11_CMAKE_DIR
    OUTPUT_STRIP_TRAILING_WHITESPACE
)

set(pybind11_DIR ${PYBIND11_CMAKE_DIR})

message(STATUS "Using pybind11 found at: ${pybind11_DIR}")
find_package(pybind11 REQUIRED)

pybind11_add_module(simple_module SHARED pybind_wrapper.cpp)

set_target_properties(simple_module PROPERTIES CXX_STANDARD 11 CXX_STANDARD_REQUIRED ON)

# needed for importing the "simple_module" module from the build directory
# this makes Python think the directory as a package making imports easier
set(INIT_PY "${CMAKE_CURRENT_BINARY_DIR}/__init__.py")
if(NOT EXISTS ${INIT_PY})
file(WRITE ${INIT_PY} "")
endif()