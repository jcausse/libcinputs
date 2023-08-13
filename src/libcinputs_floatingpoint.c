#include "libcinputs.h"

static int compare_floating_point_helper(double x, double y, double delta);

/***************************************************************************************************/

float parse_float(const char* str){
    return 0.0f;
}

double parse_double(const char* str){
    return 0.0;
}

/***************************************************************************************************/

float get_float(const char* msg, ...) {
    if (msg != NULL && strlen(msg) > 0){
        va_list ap;
        va_start(ap, msg);
        vprintf(msg, ap);
        va_end(ap);
    }
    return 0.0f;
}

double get_double(const char* msg, ...) {
    if (msg != NULL && strlen(msg) > 0){
        va_list ap;
        va_start(ap, msg);
        vprintf(msg, ap);
        va_end(ap);
    }
    return 0.0;
}

/***************************************************************************************************/

int compare_float(float x, float y){
    return compare_floating_point_helper((double) x, (double) y, DELTA_FLOAT / 10.0f);
}

int compare_double(double x, double y){
    return compare_floating_point_helper(x, y, DELTA_DOUBLE);
}

static int compare_floating_point_helper(double x, double y, double delta){
    double diff = x - y;
    bool y_is_greater = diff < 0;

    // If y is greater than x, y_is_greater will be true, and the function will return -1 if the difference is greater than or equal to delta.
    // If y is not greater than x, y_is_greater will be false, and the function will return 1 if the difference is greater than or equal to delta.
    // In both cases, the function returns 0 if the difference is smaller than delta.
    return (y_is_greater ? -1 : 1 ) * ((y_is_greater ? -diff : diff) >= delta);
}
