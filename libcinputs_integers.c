//
// Created by Juan Causse on 12/07/2023.
//

#include "libcinputs.h"

#define STRTOL_MIN_RADIX 0
#define STRTOL_MAX_RADIX 36

short parse_short(const char* str, int radix){

}

long parse_long(const char* str, int radix){
    if (str == NULL || radix < STRTOL_MIN_RADIX || radix > STRTOL_MAX_RADIX){
        errno = EINVAL;
        return 0;
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

    return range_error || non_valid_error ? 0 : parsed;
}
