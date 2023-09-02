#include "libcinputs.h"
#include "linked_list_impl.h"

static bool libcinputs_init_done = false;
static llist mem_mng_lst;

bool libcinputs_init(){
    if (libcinputs_init_done){
        return false;
    }

    libcinputs_init_done = true;
    mem_mng_lst = llist_create();
    if (mem_mng_lst == NULL){
        return false;
    }

    return true;
}

void libcinputs_lst_cleanup_cb(void* data){
    free(data);
}

void libcinputs_cleanup(){
    if (libcinputs_init_done) {
        llist_destroy(mem_mng_lst, libcinputs_lst_cleanup_cb);
    }
}