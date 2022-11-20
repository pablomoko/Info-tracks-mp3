#ifndef ADT_Vector__H
#define ADT_Vector__H
#include <stdio.h>
#include <stdlib.h>
#include "ADT_Track.h"
#include "status.h"
#include "consts.h"

typedef int (*comparator_t) (const void *, const void *);
typedef status_t (*destructor_t)(void **);
typedef status_t (*printer_t) (const void * data, const void * context, FILE *);
typedef void * (*clonator_t) (const void *);

typedef struct
{
	void ** elements;
	size_t size;
    size_t alloc_size;

	comparator_t comparator;
	destructor_t destructor;
	printer_t printer;
	clonator_t clonator;

} ADT_Vector_t;

status_t ADT_Vector_new (ADT_Vector_t **); 
status_t ADT_Vector_destroy(ADT_Vector_t **);
status_t ADT_Vector_append (ADT_Vector_t *, const void *);
status_t ADT_Vector_sort (ADT_Vector_t *vector);
status_t ADT_Vector_element_swap(void* *track1, void* *track2);

status_t ADT_Vector_set_printer    (ADT_Vector_t *, printer_t );
status_t ADT_Vector_set_comparator (ADT_Vector_t *, comparator_t);
status_t ADT_Vector_set_destructor (ADT_Vector_t *, destructor_t);

status_t ADT_Vector_export_as_csv(const ADT_Vector_t *vector,const void * delim,FILE *fo); 
status_t ADT_Vector_export_as_xml  (const ADT_Vector_t *, const void * context, FILE *);

bool_t ADT_Vector_is_empty (const ADT_Vector_t *);

#endif
