#include "fileLib.h"
#include <ctype.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int filesz(FILE *f){
	fseek(f, 0, SEEK_END);
	int size = ftell(f);
	fseek(f, 0, SEEK_SET);

	return size;
}

static FILE *open_file_read() {
    return fopen(SCRIPTS, "r");
}

static FILE *open_file_write() {
	return fopen(SCRIPTS, "w");
}

static void close_file(FILE *file){
	fclose(file);
}

void fix_word(char word[512]){
	word[0] = toupper(word[0]);
	word[strcspn(word, "\n")] = '\0';
}

char* read_line(int line){
	FILE *f = open_file_read("words");
	int count = 0;
	char word[512];
	char *pass;
	while (fgets(word, sizeof(word), f) != NULL) {
		if (count == line) {
			fix_word(word);
			pass = word;
			return pass;
		}
		else {
			count ++;
		}
	}
	close_file(f);
	return pass;
}

char* rFileConcat(){
	FILE *f = open_file_read();
	char word[512];
	int size = filesz(f);
	char *fileContents = malloc(size);
	while (fgets(word, sizeof(word), f) != NULL) {
		strcat(fileContents, word);
	}
	close_file(f);
	return fileContents;
}

int write_line(char *line){
	FILE *f = open_file_write();	
	fputs(line, f);
	close_file(f);
	return 1;
}

