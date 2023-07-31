/*
 * LibCInputs
 * libcinputs.h
 * Created by jcausse - juanignaciocausse@gmail.com
 */

#ifndef LIBCINPUTS_LIBCINPUTS_H
#define LIBCINPUTS_LIBCINPUTS_H

#define LIBCINPUTS_VERSION "0.1"

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>
#include <ctype.h>
#include <errno.h>
#include <limits.h>

// LIBCINPUTS MEMORY MANAGER
void libcinputs_init(); //TODO
void libcinputs_cleanup(); //TODO

// INTEGERS
short parse_short(const char* str, int radix);
int parse_int(const char* str, int radix);
long parse_long(const char* str, int radix);
short getshort(const char* msg, ...); //TODO
int getint(const char* msg, ...); //TODO
long getlong(const char* msg, ...); //TODO

// FLOATING POINT
float parsefloat(const char* str); //TODO
double parsedouble(const char* str); //TODO
float getfloat(const char* msg, ...); //TODO
double getdouble(const char* msg, ...); //TODO

// STRINGS
char* getstring(const char* msg, ...); //TODO

// UTILS
char* get_word(FILE* stream)

#endif //LIBCINPUTS_LIBCINPUTS_H
