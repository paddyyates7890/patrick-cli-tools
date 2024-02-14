#include "passwords.h"
#include "../cli/interface.h"
#include "../cli/othertoolcli/passwordinterface.h"
#include "../app/othertool.h"
#include "../database/sqliteConn.h"
#include "../sqlite3.h"
#include "../dbg.h"
#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>


void getPasswords(){
    getPasswordMenu();
    getPasswordsInput();
}

void getPasswordsInput(){
    char command;
    printf("\n\n");

    printf("%s(PASSWORDS)%s Enter Command: ", MAG, WHT);
    scanf(" %c", &command);

    goToPasswordsCommand(command);
}

void goToPasswordsCommand(char command){
    command = toupper(command);

    if (command == 'X') {
        getOtherTools();
    }else if (command == 'A'){
        getNewPasswordInput();
        getPasswords();
    }else if (command == 'S'){
        showPasswords();
        getPasswords();
    }else {
        printf("That was not a command");
        getPasswordsInput();
    }
}

void getNewPasswordInput(){
    char application[100];
    char passChoice;
    char* password;

    printf("\n\n%s(PASSWORDS)%sEnter the application: ", MAG, WHT); 
    scanf(" %s", application);
    
    
    printf("\n\n%s(PASSWORDS)%s(G)enerate or (E)nter a password: ", MAG, WHT); 
    scanf(" %c", &passChoice);
    
    passChoice = toupper(passChoice);
    if (passChoice == 'G'){
        password = getWordyPassword();
    }else if (passChoice == 'E'){
        password = getEnteredPassword();
    }else {
        printf("That was not an option");
    }

    if (password) {
        addPassword(password, application);
    }
}

char* getWordyPassword(){
    srand(time(0));
    int id1 = ((rand() % 6801) + 1);
    int id2 = ((rand() % 6801) + 1);
    
    char id1Str[10];
    char id2Str[10];

    sprintf(id1Str, "%d", id1);
    sprintf(id2Str, "%d", id2);

    char* sql = "SELECT WORD FROM WORDS WHERE ID = '%s' OR ID = '%s'"; 
    sqlite3_stmt* res = paramS(sql, id1Str, id2Str);
    debug("TEST");
    char* password = malloc(512);
    char* word = malloc(256);
    while(res){
        word = fieldC(res, 0);
        debug("%s", word);
        strncat(password, word, (strlen(password) + strlen(word)));
        res = step_result(res);
    }
    
    return password;
}

char* getEnteredPassword(){
    char* password = malloc(512);

    printf("\n\n%s(PASSWORDS)%sEnter the password: ", MAG, WHT);
    scanf(" %s", password);

    return password;
}

void addPassword(char* password, char* application){
    char* sql = "insert into pass_manage(password, application) values('%s', '%s');";
    int res = paramU(sql, password, application);
    
    free(password);
    
    printf("Password Has been added");
}

void showPasswords(){
   printf("Need to implement this"); 
}
