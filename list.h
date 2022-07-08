#include <stdio.h>
#include <stdlib.h>

typedef struct list
{
     char * str;
     struct list * prev;
     struct list * next;
}List;

List * add_string(char * , ssize_t ,  List * );
void clear_list(List * );
void print_list(FILE * , const List * );
