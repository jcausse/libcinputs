#include "libcinputs.h"

enum floating_point_data_types {TYPE_FLOAT, TYPE_DOUBLE, TYPE_LONG_DOUBLE};

static void parse_floating_point (const char* str, void* result, enum floating_point_data_types type);
static int compare_floating_point_helper(long double x, long double y, long double delta);
static void get_floating_point_helper(void* result, enum floating_point_data_types type);
static inline void clear_stdin(){
    int _rd;
    while ((_rd = getchar()) && _rd != '\n' && _rd != EOF);
}

/***************************************************************************************************/

float parse_float(const char* str){
    float res;
    parse_floating_point(str, (void*) &res, TYPE_FLOAT);
    if (errno != 0){
        res = 0.0f;
    }
    return res;
}

double parse_double(const char* str){
    double res;
    parse_floating_point(str, (void*) &res, TYPE_DOUBLE);
    if (errno != 0){
        res = 0.0;
    }
    return res;
}

long double parse_long_double(const char* str){
    long double res;
    parse_floating_point(str, (void*) &res, TYPE_LONG_DOUBLE);
    if (errno != 0){
        res = 0.0l;
    }
    return res;
}

static void parse_floating_point (const char* str, void* result, enum floating_point_data_types type){
    if (str == NULL){
        errno = EINVAL;
        return;
    }

    errno = 0;
    char* end;

    switch (type){
        case TYPE_FLOAT:
            *((float*) result) = strtof(str, &end);
            break;
        case TYPE_DOUBLE:
            *((double*) result) = strtod(str, &end);
            break;
        case TYPE_LONG_DOUBLE:
            *((long double*) result) = strtold(str, &end);
            break;
    }

    if (end == str) {
        errno = EINVAL;
    }
}

/***************************************************************************************************/

float get_float(const char* msg, ...) {
    if (msg != NULL && strlen(msg) > 0){
        va_list ap;
        va_start(ap, msg);
        vprintf(msg, ap);
        va_end(ap);
    }
    float res;
    get_floating_point_helper((void*) &res, TYPE_FLOAT);
    if (errno != 0){
        res = 0.0f;
    }
    return res;
}

double get_double(const char* msg, ...) {
    if (msg != NULL && strlen(msg) > 0){
        va_list ap;
        va_start(ap, msg);
        vprintf(msg, ap);
        va_end(ap);
    }
    double res;
    get_floating_point_helper((void*) &res, TYPE_DOUBLE);
    if (errno != 0){
        res = 0.0;
    }
    return res;
}

long double get_long_double(const char* msg, ...) {
    if (msg != NULL && strlen(msg) > 0){
        va_list ap;
        va_start(ap, msg);
        vprintf(msg, ap);
        va_end(ap);
    }
    long double res;
    get_floating_point_helper((void*) &res, TYPE_LONG_DOUBLE);
    if (errno != 0){
        res = 0.0l;
    }
    return res;
}

static void get_floating_point_helper(void* result, enum floating_point_data_types type){
    errno = 0;

    char floating_point_str[50];
    int read = scanf("%49s", floating_point_str);
    clear_stdin();

    if (read != 1){
        errno = EINVAL;
        return;
    }

    switch (type){
        case TYPE_FLOAT:
            *((float*) result) = parse_float(floating_point_str);
            break;
        case TYPE_DOUBLE:
            *((double*) result) = parse_double(floating_point_str);
            break;
        case TYPE_LONG_DOUBLE:
            *((long double*) result) = parse_long_double(floating_point_str);
            break;
    }
}


/***************************************************************************************************/

int compare_float(float x, float y){
    return compare_floating_point_helper((double) x, (double) y, DELTA_FLOAT / 10.0f);
}

int compare_double(double x, double y){
    return compare_floating_point_helper(x, y, DELTA_DOUBLE);
}

int compare_long_double(long double x, long double y){
    return compare_floating_point_helper(x, y, DELTA_LONG_DOUBLE);
}

static int compare_floating_point_helper(long double x, long double y, long double delta){
    long double diff = x - y;
    bool y_is_greater = diff < 0;

    // If y is greater than x, y_is_greater will be true, and the function will return -1 if the difference is greater than or equal to delta.
    // If y is not greater than x, y_is_greater will be false, and the function will return 1 if the difference is greater than or equal to delta.
    // In both cases, the function returns 0 if the difference is smaller than delta.
    return (y_is_greater ? -1 : 1 ) * ((y_is_greater ? -diff : diff) >= delta);
}
