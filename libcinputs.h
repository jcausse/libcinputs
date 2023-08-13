/*
 * LibCInputs
 * libcinputs.h
 * Created by jcausse - juanignaciocausse@gmail.com
 */

#ifndef LIBCINPUTS_LIBCINPUTS_H
#define LIBCINPUTS_LIBCINPUTS_H

#define LIBCINPUTS_VERSION "0.1"

/*
 * By changing these values, the threshold used to consider two floating-point numbers as equal can be customized.
 * If the difference between them is strictly less than the corresponding delta for the data type,
 * they are considered equal. If the difference equals delta, they are NOT considered equal.
 */
#define DELTA_FLOAT     1e-6    // Threshold used in compare_float
#define DELTA_DOUBLE    1e-12   // Threshold used in compare_double

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>
#include <ctype.h>
#include <errno.h>
#include <limits.h>

/************************************* MEMORY MANAGER *************************************/

void libcinputs_init(); //TODO
void libcinputs_cleanup(); //TODO

/************************************* INTEGERS *************************************/

/*
 * These functions parse integers (of types short, int, or long) stored as
 * NULL-terminated strings in the str parameter.
 * The radix parameter allows parsing integers in different bases.
 * Radix can be any number between 2 and 36.
 * If radix equals 0, these functions will automatically detect decimal,
 * octal (with a leading zero) or hexadecimal (starting with 0x) numbers
 * and convert them.
 * If an error occurs, zero is returned and errno is set accordingly:
 * errno is set to EINVAL if any of the following happens:
 *  * str is NULL or an empty string
 *  * radix is less than 0, greater than 36, or equals 1
 *  * No number could be found (e.g. str is "Hello" or "abc123" and radix is 0)
 * errno is set to ERANGE if the converted number is out of the valid range for
 * the given integer type (e.g. parse_int detects a number greater than INT_MAX)
 */
short parse_short(const char* str, int radix);
int parse_int(const char* str, int radix);
long parse_long(const char* str, int radix);

/*
 * These functions read integers from standard input
 * They receive a message format string and variable arguments, which are used to
 * print a message to standard output before reading from stdin. The arguments are
 * used in the same way as in printf. If msg_fmt is NULL or an empty string, no
 * message is shown and any other argument is ignored.
 * If no number could be found, 0 is returned and errno is set to EINVAL
 * If the entered number is out of range for the given type, 0 is returned and
 * errno is set to ERANGE
 */
short get_short(const char* msg_fmt, ...);
int get_int(const char* msg_fmt, ...);
long get_long(const char* msg_fmt, ...);

/************************************* FLOATING POINT *************************************/

/*
 * These functions compare two floating point values.
 * Return values:
 *  * -1 if x is less than y
 *  * 0 if x equals y
 *  * 1 if x is greater than y
 * Note that x and y are considered equal if the absolute value of the difference between them
 * is less (and not equal) than a delta value that is determined for each data type.
 */
int compare_float(float x, float y);
int compare_double(double x, double y);

float parse_float(const char* str); //TODO
double parse_double(const char* str); //TODO

float get_float(const char* msg, ...); //TODO
double get_double(const char* msg, ...); //TODO

/************************************* STRINGS *************************************/

char* get_string(const char* msg, ...); //TODO

/************************************* UTILITIES *************************************/

char* get_word(FILE* stream);

#endif //LIBCINPUTS_LIBCINPUTS_H
