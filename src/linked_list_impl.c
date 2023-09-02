// AUTOR: Juan Ignacio Causse (juanignaciocausse@gmail.com)
// FECHA DE CREACION: 28 de julio de 2023

#include "linked_list_impl.h"

typedef struct llist_node_t{
    void* data;
    struct llist_node_t* prev;
    struct llist_node_t* next;
}llist_node_t;

typedef struct llist_t{
    unsigned int size;
    llist_node_t* first_node;
    llist_node_t* last_node;
}llist_t; 

static void qsort_recursive(llist lst, llist_node_t* first, llist_node_t* last, llist_qsort_cmp comparator);
static llist_node_t* qsort_partition(llist lst, llist_node_t* first, llist_node_t* last, llist_qsort_cmp comparator);
static void swap_nodes_data(llist_node_t* node_a, llist_node_t* node_b);

/************************************************************************************************************/

llist llist_create(){
    errno = 0;
    llist new_list = malloc(sizeof(llist_t));
    if (new_list == NULL){
        errno = ENOMEM;
        return NULL;
    }

    new_list->size = 0;
    new_list->first_node = NULL;
    new_list->last_node = NULL;

    return new_list;
}

void llist_destroy(llist lst, llist_destroy_cb cb){
    if (lst == NULL){
        return;
    }

    llist_node_t* current_node = lst->first_node;

    while (current_node != NULL){
        if (cb != NULL){    // Si no se recibe un callback la funcionalidad no se utiliza
            cb(current_node->data);
        }

        llist_node_t* aux_node;

        aux_node = current_node;
        current_node = current_node->next;
        free(aux_node);
    }

    free(lst);
}

void llist_append(llist lst, void* data){
    errno = 0;
    llist_node_t* new_node = malloc(sizeof(llist_node_t));
    if (new_node == NULL){
        errno = ENOMEM;
        return;
    }

    new_node->data = data;
    new_node->prev = lst->last_node;
    new_node->next = NULL;

    if (lst->size > 0){
        lst->last_node->next = new_node;
        lst->last_node = new_node;
    }
    else{
        lst->first_node = lst->last_node = new_node;
    }
    (lst->size)++;
}

void llist_foreach(llist lst, llist_foreach_cb cb, void* param, bool reversed){
    if (cb == NULL){
        return;
    }

    unsigned int size = lst->size;
    llist_node_t* node = (reversed ? lst->last_node : lst->first_node);

    for (unsigned int i = 0; i < size; i++){
        cb(node->data, param);
        node = (reversed ? node->prev : node->next);
    }
}

unsigned int llist_size(llist lst){
    return lst->size;
}

void llist_quicksort(llist lst, llist_qsort_cmp comparator){
    qsort_recursive(lst, lst->first_node, lst->last_node, comparator);
}

/************************************************************************************************************/

static void qsort_recursive(llist lst, llist_node_t* first, llist_node_t* last, llist_qsort_cmp comparator){
    if (last != NULL && first != last && first != last->next){
        llist_node_t* pivot = qsort_partition(lst, first, last, comparator);
        qsort_recursive(lst, first, pivot->prev, comparator);
        qsort_recursive(lst, pivot->next, last, comparator);
    }
}

// No intercambia los nodos en sí, sino sus punteros data. Por esto, lst->first y lst->last seguirán apuntando
// al primer y último nodo de la lista, respectivamente
static llist_node_t* qsort_partition(llist lst, llist_node_t* first, llist_node_t* last, llist_qsort_cmp comparator){
    llist_node_t* pivot = last;                     // Tomamos el último nodo de la lista o sublista como pivote
    void* pivot_data = pivot-> data;

    llist_node_t* aux1 = first->prev;
 
    for (llist_node_t* aux2 = first; aux2 != pivot; aux2 = aux2->next){
        if (comparator(aux2->data, pivot_data) < 0){
            aux1 = (aux1 != NULL ? aux1->next : first);
            if (aux1 != aux2){
                swap_nodes_data(aux1, aux2);
            }
        }
    }

    aux1 = (aux1 != NULL ? aux1->next : first);
    swap_nodes_data(aux1, pivot);

    return aux1; // Al haber permutado aux1 con el pivote, este último quedó en el lugar de aux1
}

static void swap_nodes_data(llist_node_t* node_a, llist_node_t* node_b){
    void* aux;

    aux = node_a->data;
    node_a->data = node_b->data;
    node_b->data = aux;
}
