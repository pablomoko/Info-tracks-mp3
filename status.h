#ifndef STATUS__H
#define STATUS__H
#include <stdio.h>
#include "consts.h"

#define MSG_ERROR "ERROR"
#define MSG_OK "OK"
#define MSG_NULL_POINTER  "NULL POINTER"
#define MSG_NO_MEMORY "NO MEMORY"
#define MSG_OUT_RANGE "OUT OF RANGE"
#define MSG_INVOCATION  "INVOCATION"
#define MSG_INVALID_FORMAT "INVALID FORMAT"
#define MSG_INVALID_SORT  "INVALID SORT"
#define MSG_NO_FILE  "NO MP3 FILE"

typedef enum {
	OK,
	ERROR_NULL_POINTER,
	ERROR_NO_MEMORY,
	ERROR_OUT_OF_RANGE,
	ERROR_INVOCACION,
	ERROR_INVALID_FMT,
	ERROR_INVALID_SORT_MODE,
	ERROR_NO_FILE,
	ERROR_FILE
} status_t;

status_t show_error(status_t st);

#endif
