#include "list.h"
#include <sys/stat.h>

ino_t get_inode_num(const char * );

int main(int argc, char * argv[])
{
     FILE * in, * out;
     List * slist = NULL;
     char * line = NULL;
     size_t len = 0;
     ssize_t nread;

     switch(argc)
     {
     case 1:
	  while((nread = getline(&line, &len, stdin)) != -1)
	       slist = add_string(line, nread, slist);
	  print_list(stdout, slist);
	  break;
     case 2:
	  if((in = fopen(argv[1], "r")) == NULL)
	  {
	       fprintf(stderr, "reverse: cannot open file '%s'\n", argv[1]);
	       exit(1);
	  }
	  
	  while((nread = getline(&line, &len, in)) != -1)
	       slist = add_string(line, nread, slist);
	  print_list(stdout, slist);
	  fclose(in);
	  break;
     case 3:
	  if((in = fopen(argv[1], "r")) == NULL)
	  {
	       fprintf(stderr, "reverse: cannot open file '%s'\n", argv[1]);
	       exit(1);
	  }
	  if((out = fopen(argv[2], "w")) == NULL)
	  {
	       fprintf(stderr, "reverse: cannot open file '%s'\n", argv[2]);
	       exit(1);
	  }
	  if(get_inode_num(argv[1]) == get_inode_num(argv[2]))
	  {
	       fprintf(stderr, "reverse: input and output file must differ\n");
	       exit(1);
	  }
	  
	  while((nread = getline(&line, &len, in)) != -1)
	       slist = add_string(line, nread, slist);
	  print_list(out, slist);
	  fclose(in);
	  fclose(out);
	  break;
     default:
	  fprintf(stderr, "usage: reverse <input> <output>\n");
	  exit(1);
     }

     clear_list(slist);
     free(line);
     return 0;
}

ino_t get_inode_num(const char * path)
{
     struct stat buf;

     if(stat(path, &buf) == -1)
     {
	  fprintf(stderr, "reverse: cannot get file metadata\n");
	  exit(1);
     }

     return buf.st_ino;
}
	  

	  
	  
     
