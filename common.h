#ifndef COMMON__H
#define COMMON__H
#include "status.h"

status_t open_file(FILE **,const char *);
status_t close_file(FILE **f);
status_t destroy_file(FILE **f,const char *file_name);
#endif
