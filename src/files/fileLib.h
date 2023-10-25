#include <stdio.h>

#ifndef _FILELIB_ACTIVE
#define _FILELIB_ACTIVE

int filesz(FILE *f);
FILE *open_file_read(char *file);
FILE *open_file_write(char *file);
char* read_line(int line);
char* rFileConcat(char *file);
void close_file(FILE *file);
int write_line(char *line, char *file);

#endif 
