// AUTOR: Juan Ignacio Causse (juanignaciocausse@gmail.com)
// FECHA DE CREACION: 28 de julio de 2023

#ifndef _LINKED_LIST_IMPL_H_28072023_
#define _LINKED_LIST_IMPL_H_28072023_

#include <stdlib.h>                 // malloc, free
#include <errno.h>                  // errno
#include <stdbool.h>

typedef struct llist_t* llist;      // TAD (Tipo Abstracto de Datos) de lista
typedef void (* llist_destroy_cb) (void*);  // Callback para la función de destruir lista
typedef void (* llist_foreach_cb) (void*, void*); // Callback para el foreach
typedef int (* llist_qsort_cmp) (void*, void*); // Callback para comparar dos elementos de la lista al usar quicksort

/*
 * Crea una lista vinculada (linked list)
 * No recibe parámetros
 * Devuelve la lista creada (vacía)
 * En caso de falta de memoria, devuelve NULL y errno tendrá el valor ENOMEM
*/
llist llist_create();

/*
 * Destruye una lista
 * Recibe la lista y un callback que permite liberar la memoria reservada
 * para los datos de cada nodo. Para no utilizar esta funcionalidad, cb debe ser NULL
 * No devuelve nada
*/
void llist_destroy(llist lst, llist_destroy_cb cb);

/*
 * Agrega un nodo al final de la lista (funciona también para listas vacías)
 * Recibe la lista, y el puntero a los datos a agregar
 * No devuelve nada
 * En caso de falta de memoria, errno tendrá el valor ENOMEM
*/
void llist_append(llist lst, void* data);

/*
 * Ejecuta una acción definida por el usuario para cada elemento en la lista
 * Recibe la lista, un callback con la acción a realizar y un parámetro opcional para el callback
 * El ultimo parámetro, reversed, permite recorrer la lista en orden inverso si su valor es distinto de cero
 * Si reversed = 0, el orden de recorrido es el natural
 * No devuelve nada
*/
void llist_foreach(llist lst, llist_foreach_cb cb, void* param, bool reversed);

/*
 * Devuelve la cantidad de nodos de la lista
 * Recibe la lista
 * No devuelve nada
*/
unsigned int llist_size(llist lst);

/*
 * Ordena la lista (de forma permanente, NO genera una copia ordenada) utilizando el algoritmo quicksort
 * Recibe la lista y un comparador
 * No devuelve nada
*/
void llist_quicksort(llist lst, llist_qsort_cmp comparator);

#endif //_LINKED_LIST_IMPL_H_28072023_
