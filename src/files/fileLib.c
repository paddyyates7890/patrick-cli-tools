#include "fileLib.h"
#include "../linked-list/linkedList.h"
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

FILE *open_file_read(char *file) {
    return fopen(file, "r");
}

FILE *open_file_write(char *file) {
	return fopen(file, "a");
}

void close_file(FILE *file){
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

int rLines(char *file){
    FILE *f = open_file_read(file);

    int count = 0;
    char c;
    for (c = getc(f); c != EOF; c = getc(f)) {
        if (c == '\n') {
            count = count + 1;
        }
    }

    close_file(f);
    return count;
}

char* rFileConcat(char *file){
	FILE *f = open_file_read(file);
	char word[512];
	int size = filesz(f);
	char *fileContents = malloc(size);
	while (fgets(word, sizeof(word), f) != NULL) {
		strcat(fileContents, word);
	}
	close_file(f);
	return fileContents;
}

linkedList* rFileList(char *file){
    linkedList *list = create_list();
    int noLines = rLines(file);
    
    if (noLines >= 1) {
        FILE *f = open_file_read(file);
        char lines[noLines][512];
        
        int i = 0;
        while(fgets(lines[i], sizeof(lines[i]), f)) {
            LLpush(list, lines[i]);
            i = i + 1;
        }
        close_file(f);
    }

    return list;
}

int write_line(char *line, char *file){
	FILE *f = open_file_write(file);
    fprintf(f, "%s\n",line);    
    close_file(f);

	return 1;
}

