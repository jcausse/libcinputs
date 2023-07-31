#include "libcinputs.h"

static bool _init_done = false;

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
