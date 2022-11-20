#include "ADT_Vector.h"

status_t ADT_Vector_new (ADT_Vector_t **vector){

    if (vector == NULL){
        return ERROR_NULL_POINTER;
    }

    if ((*vector = (ADT_Vector_t*) malloc(sizeof(ADT_Vector_t))) == NULL){
        return ERROR_NO_MEMORY;
    }

    if (((*vector)->elements = (void*) malloc( INIT_CHOP * sizeof (void*))) == NULL){
        free(*vector);
        *vector = NULL;
        return ERROR_NO_MEMORY;
    }

    (*vector)->printer = NULL;
    (*vector)->destructor = NULL;
    (*vector)->comparator = NULL;
    (*vector)->clonator = NULL;
    (*vector)->alloc_size = INIT_CHOP;
    (*vector)->size = 0 ;

    return OK;
}

status_t ADT_Vector_set_destructor (ADT_Vector_t *vector, destructor_t destructor){ /*LE PASO EL DESTRUCTOR DE TRACKS PARA QUE BORRE CADA ELEMENTO DE CADA POSICION*/

    if (vector == NULL){
        return ERROR_NULL_POINTER;
    }

    vector->destructor = destructor;

    return OK;

}

status_t ADT_Vector_set_comparator (ADT_Vector_t *vector, comparator_t comparator){

    if (vector == NULL){
        return ERROR_NULL_POINTER;
    }

    vector->comparator = comparator ;

    return OK;
}

status_t ADT_Vector_destroy(ADT_Vector_t **vector){
    status_t st;
    size_t i;

    if (vector == NULL){
        return ERROR_NULL_POINTER;
    }

    for ( i = 0; i < (*vector)->size; i++){
        if ((st=((*vector)->destructor(&((*vector)->elements[i]))))!= OK){
            return st;
        }
        ((*vector)->elements[i])= NULL;
    }
    free((*vector)->elements);
    free(*vector);
    *vector = NULL;

    return OK;
}

status_t ADT_Vector_append (ADT_Vector_t *vector, const void *element){

    void *aux;

    if (vector == NULL || element == NULL){
        return ERROR_NULL_POINTER;
    }

    if ((vector->alloc_size)>(vector->size)){
        if ((aux = (void**) realloc((vector->elements), ((vector->size) + CHOP_SIZE)*sizeof(void*)) ) == NULL){
            ADT_Vector_destroy(&vector);
            return ERROR_NO_MEMORY;
        }
        vector->elements = aux;
        (vector->alloc_size) = (vector->alloc_size) + CHOP_SIZE ;
    }
    vector->elements[vector->size] = (void*) element;
    (vector->size)++;

    return OK;
}

status_t ADT_Vector_sort (ADT_Vector_t *vector){

    status_t st;
    size_t i,j,l;
    l = vector->size;

    for(i = 0; i < l - 1; i++) {
        for(j = 0; j < (l - 1 - i); j++) {
            if((vector->comparator)(vector->elements[j],vector->elements[j+1])<0) {
              if ((st = ADT_Vector_element_swap(&vector->elements[j],&vector->elements[j+1]))!= OK){
                  show_error(st);
                  return EXIT_FAILURE;
              }
            }
        }
    }
    return OK;
}


bool_t ADT_Vector_is_empty (const ADT_Vector_t *vector){

    return (vector->size) == 0 ? TRUE : FALSE;

}

status_t ADT_Vector_set_printer    (ADT_Vector_t *vector, printer_t printer){

    if (vector == NULL){
        return ERROR_NULL_POINTER;
    }

    vector->printer = printer ;

    return OK;

}

status_t ADT_Vector_export_as_csv(const ADT_Vector_t *vector,const void* delim,FILE*fo){

    status_t st;
    size_t i;

    if (vector == NULL || fo == NULL){
        return ERROR_NULL_POINTER;
    }

    for (i= 0; i < vector->size; i++){
        if ((st = ((vector)->printer(((vector)->elements[i]),delim,fo)) ) != OK){
            return st;
        }
    }

    return OK;
}

status_t ADT_Vector_export_as_xml(const ADT_Vector_t *vector,const void * context, FILE * fo ){

    status_t st;
    size_t i;

    if (vector == NULL || fo == NULL ){
        return ERROR_NULL_POINTER;
    }

    fprintf(fo,"<?xml version=%s ?>\n",(char*)context);
    fprintf(fo,"<tracks>\n");
    for (i= 0; i < vector->size; i++){
        if ((st=((vector)->printer(((vector)->elements[i]),context,fo)))!= OK){
            return st;
        }
    }
    fprintf(fo,"</tracks>\n");
    return OK;
}

status_t ADT_Vector_element_swap(void* *track1, void* *track2){
  
    ADT_Track_t *aux;

    aux = (ADT_Track_t*) *track1;
    *track1 =(ADT_Track_t*) *track2;
    *track2 = aux;

    return OK;
}

