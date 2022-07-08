#include "list.h"
#include <string.h>

List * add_string(char * new_str, ssize_t nread, List * slist)
{
     List * new_node = (List *) malloc(sizeof(List));
     if(new_node == NULL)
     {
	  fprintf(stderr, "malloc failed\n");
	  exit(1);
     }
     
     new_node->str = (char *) malloc(nread + 1); // +1 for '\0'
     if(new_node->str == NULL)
     {
	  fprintf(stderr, "malloc failed\n");
	  exit(1);
     }
     strcpy(new_node->str, new_str);
     
     if(slist == NULL)
     {
	  slist = new_node;
	  slist->prev = slist->next = NULL;
     }
     else
     {
	  slist->next = new_node;
	  new_node->prev = slist;
	  slist = new_node;
	  slist->next = NULL;
     }

     return slist;
}

void clear_list(List * slist)
{
     List * temp;

     while(slist != NULL)
     {
	  temp = slist->prev;
	  free(slist->str);
	  free(slist);
	  slist = temp;
     }
}
	  
void print_list(FILE * fp, const List * slist)
{
     while(slist != NULL)
     {
	  fprintf(fp, "%s", slist->str);
	  slist = slist->prev;
     }
}
	  
     
