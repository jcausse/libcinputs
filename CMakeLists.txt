cmake_minimum_required(VERSION 3.25)
project(libcinputs C)

set(CMAKE_C_STANDARD 11)

add_executable(libcinputs libcinputs.h libcinputs_tests.c libcinputs_integers.c libcinputs_floatingpoint.c libcinputs_string.c)
