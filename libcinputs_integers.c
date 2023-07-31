#include "libcinputs.h"

#define STRTOL_MIN_RADIX 0
#define STRTOL_MAX_RADIX 36

enum datatypes {_GET_TYPE_SHORT, _GET_TYPE_INT, _GET_TYPE_LONG};

static long get_integer_helper(enum datatypes type);


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
    if (str == NULL || radix < STRTOL_MIN_RADIX || radix > STRTOL_MAX_RADIX){
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

short getshort(const char* msg, ...){
    if (msg != NULL && strlen(msg) > 0){
        va_list ap;
        va_start(ap, msg);
        vprintf(msg, ap);
        va_end(ap);
    }
    return (short) get_integer_helper(_GET_TYPE_SHORT);
}

int getint(const char* msg, ...){
    if (msg != NULL && strlen(msg) > 0){
        va_list ap;
        va_start(ap, msg);
        vprintf(msg, ap);
        va_end(ap);
    }
    return (int) get_integer_helper(_GET_TYPE_INT);
}

long getlong(const char* msg, ...) {
    if (msg != NULL && strlen(msg) > 0){
        va_list ap;
        va_start(ap, msg);
        vprintf(msg, ap);
        va_end(ap);
    }
    return get_integer_helper(_GET_TYPE_LONG);
}

static long get_integer_helper(enum datatypes type){
    return 0;
}
