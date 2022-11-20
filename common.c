#include "common.h"

status_t open_file(FILE **archivo,const char *nombre_archivo){

    if(nombre_archivo == NULL || archivo == NULL){
		return ERROR_NULL_POINTER;
	}

    if((*archivo=fopen(nombre_archivo,"wt"))==NULL){
		return ERROR_NO_FILE;
	}
	return OK;
}

status_t close_file(FILE **f){

    if (f == NULL){
        return ERROR_NULL_POINTER;
    }

	if((fclose(*f))!=0){
		return ERROR_FILE;
	}
	*f=NULL;

	return OK;
}

status_t destroy_file(FILE **f,const char *file_name){

    status_t st;

    if (f == NULL || file_name == NULL){
        return ERROR_NULL_POINTER;
    }
    if((st = close_file(f))!=OK){
        return st;
    }

    remove(file_name);

    return OK;
}
