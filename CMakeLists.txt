cmake_minimum_required(VERSION 3.22)
project(libcinputs C)

set(CMAKE_C_STANDARD 11)

add_executable(libcinputs src/libcinputs.h libcinputs_tests.c src/libcinputs_integers.c src/libcinputs_floatingpoint.c src/libcinputs_string.c src/libcinputs_memmng.c src/linked_list_impl.h src/linked_list_impl.c)
