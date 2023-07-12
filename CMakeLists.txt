cmake_minimum_required(VERSION 3.25)
project(libcinputs C)

set(CMAKE_C_STANDARD 11)

add_library(libcinputs libcinputs.h libcinputs.c libcinputs_tests.c)
