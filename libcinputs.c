//
// Created by Juan Causse on 12/07/2023.
//

#include "libcinputs.h"

typedef struct mem_alloc_unit{
    unsigned long size;
    void* addr;
    struct mem_alloc_unit * next;
} mem_alloc_unit;

static inline void stdin_clr();

int parseint(const char* str){
    errno = 0;
    int res;

    if (str == NULL || *str == '\0'){
        errno = EINVAL;
        stdin_clr();
        return 0;
    }
    if (sscanf(str, "%d", &res) != 1){
        errno = EINVAL;
        stdin_clr();
        return 0;
    }
    return res;
}

double parsedouble(const char* str){
    errno = 0;
    double res;

    if (str == NULL || *str == '\0'){
        errno = EINVAL;
        stdin_clr();
        return 0.0;
    }
    if (sscanf(str, "%lg", &res) != 1){
        errno = EINVAL;
        stdin_clr();
        return 0.0;
    }
    return res;
}

/************************************************************/

int getint(const char* msg, ...){
    return 0;
}

double getdouble(const char* msg, ...){
    return 0;
}

char* getstring(const char* msg, ...){
    return NULL;
}

/************************************************************/

static inline void stdin_clr(){
    while (getchar() != '\n');
}
