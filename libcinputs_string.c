//
// Created by Juan Causse on 12/07/2023.
//

#include "libcinputs.h"

typedef struct mem_alloc_unit{
    unsigned long size;
    void* addr;
    struct mem_alloc_unit * next;
} mem_alloc_unit;
