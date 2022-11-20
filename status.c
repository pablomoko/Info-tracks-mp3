#include "status.h"

string status[] = {
    MSG_OK,
    MSG_NULL_POINTER,
    MSG_NO_MEMORY ,
    MSG_OUT_RANGE,
    MSG_INVOCATION,
    MSG_INVALID_FORMAT,
    MSG_INVALID_SORT,
    MSG_NO_FILE
};

status_t show_error(status_t st){

   fprintf(stdout,"%s: %s\n",MSG_ERROR ,status[st]);

   return OK;

}
