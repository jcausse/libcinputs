cmake_minimum_required(VERSION 3.22)
project(libcinputs C)

set(CMAKE_C_STANDARD 11)

add_executable(libcinputs libcinputs.h libcinputs_tests.c libcinputs_integers.c libcinputs_floatingpoint.c libcinputs_string.c libcinputs_memmng.c linked_list_impl.h linked_list_impl.c)
