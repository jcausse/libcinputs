//
// Created by Juani on 7/16/2023.
//

#include "libcinputs.h"

typedef struct mem_alloc_unit{
    unsigned long size;
    void* addr;
    struct mem_alloc_unit * next;
} mem_alloc_unit;

typedef struct mem_alloc_unit * mem_unit;

static bool _init_done = false;
mem_unit _first_node = NULL;

void libcinputs_init(){
    if (_init_done){
        return;
    }
    _init_done = true;

}

void libcinputs_cleanup(){
    if (! _init_done){
        return;
    }

}
