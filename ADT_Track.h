#ifndef ADT_Track__H
#define ADT_Track__H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "status.h"
#include "consts.h"

typedef struct{
        char name[MAX_NAME_LEN+1];
        char artist[MAX_ARTIST_LEN+1];
        unsigned char genre;
        unsigned short year;
} ADT_Track_t;

status_t ADT_Track_new (ADT_Track_t **);
status_t ADT_Track_set_name(ADT_Track_t *, const string name);
status_t ADT_Track_set_artist(ADT_Track_t *, const string artist);
status_t ADT_Track_genre(ADT_Track_t *, unsigned char genre);
status_t ADT_Track_set_year(ADT_Track_t *, unsigned short year);
status_t ADT_Track_destroy(void **);

status_t ADT_Track_export_as_xml (const ADT_Track_t *, const void * context, FILE * fo);
status_t ADT_Track_export_as_csv (const ADT_Track_t *, const void * delim,FILE *fo);


int ADT_Track_compare_by_name(const void *, const void *);
int ADT_Track_compare_by_artist(const void *, const void *);
int ADT_Track_compare_by_genre(const void *, const void *);
int ADT_Track_compare_by_year(const void *, const void *);

#endif
