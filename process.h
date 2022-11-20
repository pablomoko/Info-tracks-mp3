#ifndef PROCESS__H
#define PROCESS__H
#include "status.h"
#include "ADT_Track.h"
#include "ADT_Vector.h"


status_t load_mp3_header_to_ADT_Track (const char header[], ADT_Track_t **track);
status_t procces_mp3_files(int argc, char *argv[],ADT_Vector_t *vector);
status_t sort_mp3_files(char* sort, ADT_Vector_t *vector);
status_t print_tracks(char *fmt,ADT_Vector_t *vector, FILE*fo);
status_t destroy_vector(ADT_Vector_t *vector, destructor_t destructor);

#endif
