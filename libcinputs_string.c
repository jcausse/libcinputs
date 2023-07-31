#include "libcinputs.h"

#define STR_BLOCK 10

/*
 * Lee el archivo de a un caracter y devuelve una palabra (delimitada por cualquier caracter de espacio en blanco o EOF)
 * No se utilizo fgets ya que agrega los LF / CRLF al final del string y se requiere un recorrido extra para eliminar los
 * mismos, aumentando la complejidad temporal del programa. Una forma menos eficiente es usar fgets y luego strcspn
*/
char* get_word(FILE* stream){
    errno = 0;
    char* wrd = malloc(STR_BLOCK * sizeof(char)); // Se reserva memoria de a bloques para almacenar el string
    if (!wrd){
        errno = ENOMEM;
        return NULL;
    }
    int chr, index = 0, done = 0, foundchr = 0;

    do{
        chr = fgetc(stream);
        if (chr == EOF || (foundchr && isspace(chr))){
            done = 1;
        }
        else if(!isspace(chr)){ // Ignorar los espacios adicionales al comienzo si no se encontro ningun caracter
            foundchr = 1;
            wrd[index++] = (unsigned char) chr;
            if (index % STR_BLOCK == 0){        // Incrementar el tamaño del string en un bloque al utilizar todo
                char* wrd_aux = realloc(wrd, (index + STR_BLOCK) * sizeof(char)); // el espacio previamente reservado
                if (!wrd_aux){
                    free(wrd);
                    errno = ENOMEM;
                    return NULL;
                }
                wrd = wrd_aux;
            }
        }
    } while (!done);

    if (foundchr == 0){
        free(wrd);
        return NULL;
    }

    wrd[index] = '\0';
    
    char* wrd_aux = realloc(wrd, (index + 1) * sizeof(char)); // Recortar el tamaño final del string para que ocupe solo lo necesario
    if (!wrd_aux){
        free(wrd);
        errno = ENOMEM;
        return NULL;
    }
    return wrd_aux;
}
