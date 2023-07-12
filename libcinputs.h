//
// Created by Juan Causse on 12/07/2023.
//

#ifndef LIBCINPUTS_LIBCINPUTS_H
#define LIBCINPUTS_LIBCINPUTS_H

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>
#include <ctype.h>
#include <errno.h>
#include <limits.h>

short parse_short(const char* str, int radix);
int parse_int(const char* str, int radix);
long parse_long(const char* str, int radix);

unsigned short parse_u_short(const char* str, int radix);
unsigned int parse_u_int(const char* str, int radix);
unsigned long parse_u_long(const char* str, int radix);

float parsefloat(const char* str);
double parsedouble(const char* str);

int getint(const char* msg, ...);
double getdouble(const char* msg, ...);
char* getstring(const char* msg, ...);

#endif //LIBCINPUTS_LIBCINPUTS_H
