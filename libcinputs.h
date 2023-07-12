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

int parseint(const char* str);
double parsedouble(const char* str);

int getint(const char* msg, ...);
double getdouble(const char* msg, ...);
char* getstring(const char* msg, ...);

#endif //LIBCINPUTS_LIBCINPUTS_H
