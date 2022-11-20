#ifndef CONSTS__H
#define CONSTS__H

#define INIT_CHOP  20
#define CHOP_SIZE  5
#define NUL       '\0'
#define MAX_NAME_LEN 15
#define MAX_ARTIST_LEN 20
#define DELIMITER_CSV "|"
#define XML_VERSION "1.0"
typedef char * string;

/**********MP3 HEADER***********/
#define MP3_HEADER_SIZE		128

#define LEXEM_START_TITLE   3
#define LEXEM_SPAN_TITLE   30

#define LEXEM_START_ARTIST 33
#define LEXEM_SPAN_ARTIST  30

#define LEXEM_START_YEAR   93
#define LEXEM_SPAN_YEAR     4

#define LEXEM_START_GENRE  127
#define LEXEM_SPAN_GENRE     1
/********************************/

/**************CMD****************/
#define CMD_ARG_POS_FIRST_VALUE_TOKEN  1
#define CMD_ARG_FORMAT_TOKEN 2
#define CMD_ARG_FIRST_VALUE_TOKEN     "-fmt"
#define XML_FORMAT "xml"
#define CSV_FORMAT "csv"
#define CMD_ARG_POS_SECOND_VALUE_TOKEN 3
#define CMD_ARG_SORT_TOKEN 4
#define CMD_ARG_SECOND_VALUE_TOKEN    "-sort"
#define SORT_MODE_NAME "name"
#define SORT_MODE_ARTIST "artist"
#define SORT_MODE_YEAR "year"
#define SORT_MODE_GENRE "genre"
#define CMD_ARG_POS_THIRD_VALUE_TOKEN 5
#define CMD_ARG_THIRD_VALUE_TOKEN    "-out"
#define CMD_OUT_TOKEN 6
#define CMD_ARG_POS_SEVENTH_VALUE_TOKEN 7
/*********************************/

typedef enum{
    TRUE,
    FALSE
}bool_t;


#endif
