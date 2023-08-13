#include "libcinputs.h"

#define STRTOL_MIN_RADIX 2
#define STRTOL_MAX_RADIX 36

enum data_types {GET_TYPE_SHORT, GET_TYPE_INT, GET_TYPE_LONG};

static long get_integer_helper(enum data_types type);
static inline void clear_stdin(){
    int _rd;
    while ((_rd = getchar()) && _rd != '\n' && _rd != EOF);
}


/***************************************************************************************************/

short parse_short(const char* str, int radix){
    long res = parse_long(str, radix);
    if (res > SHRT_MAX || res < SHRT_MIN){
        errno = ERANGE;
        return (short) 0;
    }
    return (short) res;
}

int parse_int(const char* str, int radix){
    long res = parse_long(str, radix);
    if (res > INT_MAX || res < INT_MIN){
        errno = ERANGE;
        return (int) 0;
    }
    return (int) res;
}

long parse_long(const char* str, int radix){
    if (str == NULL || (radix != 0 && (radix < STRTOL_MIN_RADIX || radix > STRTOL_MAX_RADIX))){
        errno = EINVAL;
        return 0L;
    }

    errno = 0;
    char* end;
    bool range_error = false, non_valid_error = false;

    long parsed = strtol(str, &end, radix);

    if (end == str){
        non_valid_error = true;
        errno = EINVAL;
    }
    else{
        range_error = errno == ERANGE;
    }

    return range_error || non_valid_error ? 0L : parsed;
}

/***************************************************************************************************/

short get_short(const char* msg, ...){
    if (msg != NULL && strlen(msg) > 0){
        va_list ap;
        va_start(ap, msg);
        vprintf(msg, ap);
        va_end(ap);
    }
    return (short) get_integer_helper(GET_TYPE_SHORT);
}

int get_int(const char* msg, ...){
    if (msg != NULL && strlen(msg) > 0){
        va_list ap;
        va_start(ap, msg);
        vprintf(msg, ap);
        va_end(ap);
    }
    return (int) get_integer_helper(GET_TYPE_INT);
}

long get_long(const char* msg, ...) {
    if (msg != NULL && strlen(msg) > 0){
        va_list ap;
        va_start(ap, msg);
        vprintf(msg, ap);
        va_end(ap);
    }
    return get_integer_helper(GET_TYPE_LONG);
}

static long get_integer_helper(enum data_types type){
    errno = 0;

    char num_str[30] = {0};
    int read = scanf("%29s", num_str);
    clear_stdin();

    if (read != 1){
        errno = EINVAL;
        return 0L;
    }

    long res = 0;
    switch (type){
        case GET_TYPE_SHORT: res = parse_short(num_str, 0); break;
        case GET_TYPE_INT: res = parse_int(num_str, 0); break;
        case GET_TYPE_LONG: res = parse_long(num_str, 0); break;
    }

    return res;
}
