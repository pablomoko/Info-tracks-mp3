#include "process.h"

status_t load_mp3_header_to_ADT_Track (const char header[], ADT_Track_t **track){
    char buf[MP3_HEADER_SIZE];

    if (header == NULL || track == NULL){
       return ERROR_NULL_POINTER;
    }

    memcpy(buf,header+LEXEM_START_TITLE,LEXEM_SPAN_TITLE);
    buf[LEXEM_SPAN_TITLE] = '\0';
    ADT_Track_set_name(*track,buf);

    memcpy(buf,header+LEXEM_START_ARTIST,LEXEM_SPAN_ARTIST);
    buf[LEXEM_SPAN_ARTIST] = '\0';
    ADT_Track_set_artist(*track,buf);

    *buf = header[LEXEM_START_GENRE];
    ADT_Track_genre(*track,*buf);

    memcpy(buf,header+LEXEM_START_YEAR,LEXEM_SPAN_YEAR);
    buf[LEXEM_SPAN_YEAR] = '\0';
    ADT_Track_set_year(*track,atoi(buf));


    return OK;
}

status_t procces_mp3_files(int argc, char *argv[],ADT_Vector_t *vector){

    ADT_Track_t *track;
    status_t st;
    FILE *f;
    size_t length,i;
    char header[MP3_HEADER_SIZE];

    for( i = CMD_ARG_POS_SEVENTH_VALUE_TOKEN; i < argc; i++){
        if ((f = fopen(argv[i],"rb")) == NULL){
            return ERROR_NO_FILE;
        }
        fseek(f, 0, SEEK_END);
        length=ftell(f);
        fseek(f,length-MP3_HEADER_SIZE,SEEK_SET);

        fread(header,sizeof(char),MP3_HEADER_SIZE,f);

        if ((st=ADT_Track_new(&track))!=OK){
            return st;
        }

        if ((st = load_mp3_header_to_ADT_Track(header,&track))!= OK){
            return st;
        }

        if ((st = ADT_Vector_append (vector,track))!= OK){
            return st;
        }

        fclose(f);
    }

    return OK;
}

status_t sort_mp3_files(char* sort, ADT_Vector_t *vector){
    status_t st;
    bool_t status = FALSE;

    if (sort == NULL || vector == NULL){
       return ERROR_NULL_POINTER;
    }

    if (!strcmp(sort,SORT_MODE_NAME)){
        if ((st = ADT_Vector_set_comparator(vector,ADT_Track_compare_by_name))!= OK){
            return st;
        }
        status = TRUE;
    }

    if (!strcmp(sort,SORT_MODE_ARTIST)){
        if ((st = ADT_Vector_set_comparator(vector,ADT_Track_compare_by_artist))!= OK){
            return st;
        }
        status = TRUE;;
    }

    if (!strcmp(sort,SORT_MODE_YEAR)){
        if ((st = ADT_Vector_set_comparator(vector,ADT_Track_compare_by_year))!= OK){
            return st;
        }
        status = TRUE;;
    }

    if (!strcmp(sort,SORT_MODE_GENRE)){
        if ((st = ADT_Vector_set_comparator(vector,ADT_Track_compare_by_genre))!= OK){
            return st;
        }
        status = TRUE;;
    }

    if (status == FALSE){
        return ERROR_INVALID_SORT_MODE;
    }

    if ((st = ADT_Vector_sort(vector))!= OK){
        return st;
    }    
    
    return OK;
}

status_t print_tracks(char *fmt,ADT_Vector_t* vector, FILE*fo){

    status_t st;
    bool_t status = FALSE;

    if (fmt == NULL || vector == NULL || fo == NULL){
        return ERROR_NULL_POINTER;
    }

    if (!strcmp(fmt,CSV_FORMAT)){
        if ((st = ADT_Vector_set_printer(vector,ADT_Track_export_as_csv)) != OK ){
            return st;
        }
        if ((st = ADT_Vector_export_as_csv(vector,DELIMITER_CSV,fo) )!= OK){
            return st;
        }
        status = TRUE;
    }

    if (!strcmp(fmt,XML_FORMAT)){
       
        if ((st = ADT_Vector_set_printer(vector,ADT_Track_export_as_xml))!= OK){
           return st;
        }
        if ((st = ADT_Vector_export_as_xml(vector,XML_VERSION,fo) )!= OK){
            return st;
        }
        status = TRUE;
    }

    if (status == FALSE){
        return ERROR_INVALID_FMT;
    }
    
    return OK;
}

status_t destroy_vector(ADT_Vector_t *vector, destructor_t destructor){
    status_t st;

    if (vector == NULL){
        return ERROR_NULL_POINTER;
    }

    if ((st = ADT_Vector_set_destructor (vector,ADT_Track_destroy))!= OK){
        return st;
    }

    if ((st = ADT_Vector_destroy(&vector))!= OK){
        return st;
    }

    return OK;
}
