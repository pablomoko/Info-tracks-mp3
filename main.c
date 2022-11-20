#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "process.h"
#include "common.h"
#include "consts.h"
#include "status.h"
#include "ADT_Track.h"
#include "ADT_Vector.h"


status_t validate_arguments(int argc, char *argv[]);

int main(int argc, char *argv[]){
    FILE*fo;
    status_t st;
    ADT_Vector_t *vector;

    if ((st = validate_arguments(argc, argv)) != OK){
        show_error(st);
        return EXIT_FAILURE;
    }
   
    if ((st = ADT_Vector_new(&vector)) != OK){
        show_error(st);
        return EXIT_FAILURE;
    }

    if ((st = procces_mp3_files(argc,argv,vector))!= OK){
        show_error(st);
        if ((st = destroy_vector(vector,ADT_Track_destroy))!= OK){
            show_error(st);
        }
        return EXIT_FAILURE;
    }

    if ((st = sort_mp3_files(argv[CMD_ARG_SORT_TOKEN],vector)) != OK){
        show_error(st);
        if ((st = destroy_vector(vector,ADT_Track_destroy))!= OK){
            show_error(st);
        }
        return EXIT_FAILURE;
    }

    if ((st = open_file(&fo,argv[CMD_OUT_TOKEN])) != OK){
        show_error(st);
        if ((st = destroy_vector(vector,ADT_Track_destroy))!= OK){
            show_error(st);
        }   
        return EXIT_FAILURE;
    }
    
    if ((st = print_tracks(argv[CMD_ARG_FORMAT_TOKEN],vector,fo) )!= OK){
        show_error(st);
    }

    if ((st = destroy_vector(vector,ADT_Track_destroy))!= OK){
        show_error(st);
        return EXIT_FAILURE;
    }

    if ((st = close_file(&fo))!= OK){
        show_error(st);    
        return EXIT_FAILURE;
    }
    
    return EXIT_SUCCESS;

}

status_t validate_arguments(int argc, char *argv[]) {

    if (argv == NULL){
        return ERROR_NULL_POINTER;
    }

    if(strcmp(argv[CMD_ARG_POS_FIRST_VALUE_TOKEN], CMD_ARG_FIRST_VALUE_TOKEN)) {
        return ERROR_INVOCACION;
    }

    if(strcmp(argv[CMD_ARG_POS_SECOND_VALUE_TOKEN], CMD_ARG_SECOND_VALUE_TOKEN)) {
        return ERROR_INVOCACION;
    }
    if(strcmp(argv[CMD_ARG_POS_THIRD_VALUE_TOKEN], CMD_ARG_THIRD_VALUE_TOKEN)) {
        return ERROR_INVOCACION;
    }
    return OK;
}

