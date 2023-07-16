//
// Created by Juan Causse on 12/07/2023.
//

#include "libcinputs.h"

#define STRTOL_MIN_RADIX 0
#define STRTOL_MAX_RADIX 36

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
