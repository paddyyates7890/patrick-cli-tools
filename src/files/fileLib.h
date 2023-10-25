#include <stdio.h>

#ifndef _FILELIB_ACTIVE
#define _FILELIB_ACTIVE

#define SCRIPTS "scripts.txt"

int filesz(FILE *f);
static FILE *open_file_read();
static FILE *open_file_write();
char* read_line(int line);
char* rFileConcat();
static void close_file(FILE *file);
int write_line(char *line);

#endif 
