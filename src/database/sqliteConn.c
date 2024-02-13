#include "../dbg.h"
#include "sqliteConn.h"
#include "../sqlite3.h"
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void closeDB(sqlite3 *db, sqlite3_stmt* res){
    if (res != NULL) {
        sqlite3_finalize(res);
    }
    sqlite3_close_v2(db);
}

sqlite3* openDB(){
    sqlite3* db;
    int status = 0;
    
    char* database_location = malloc(strlen(getenv("HOME")) + strlen(DATABASE) + 1);
    strcpy(database_location, getenv("HOME"));
    strcat(database_location, DATABASE);
    
    int flags = SQLITE_OPEN_READWRITE | SQLITE_OPEN_CREATE;
    status = sqlite3_open_v2(database_location, &db, flags, NULL);
    check((status == SQLITE_OK), "Failed to open database %s", database_location);
    
    free(database_location);
    return db;
error:
    closeDB(db, NULL);
    free(database_location);
    exit(0); 
}

sqlite3_stmt* select_data(sqlite3* db, char* sql){
    int status = 0;
    
    sqlite3_stmt *res;

    status = sqlite3_prepare_v2(db, sql, -1, &res, 0);
    check((status == SQLITE_OK), "Failed to fetch data %s ", sqlite3_errmsg(db));
    
    status = sqlite3_step(res);
    check((status == SQLITE_ROW), "Failed to select row %s ", sqlite3_errmsg(db));

    return res;
error:
    closeDB(db, res);
    exit(0);
}

sqlite3_stmt* step_result(sqlite3_stmt* res){
    int status = 0;

    status = sqlite3_step(res);
    if (status != SQLITE_ROW) {
        sqlite3_finalize(res);
        res = NULL;
    }

    return res;
}

int update_data(sqlite3* db, char* sql){
    char* err_msg = 0;
    int status = 0;

    status = sqlite3_exec(db, sql, 0, 0, &err_msg);
    check((status == SQLITE_OK), "Failed to insert data %s ", err_msg);
    
    sqlite3_free(err_msg);

    return 0;
error:
    sqlite3_free(err_msg);
    closeDB(db, NULL);
    exit(0);
}

char* fieldC(sqlite3_stmt* res, int indx){
    char* field = (char*) sqlite3_column_text(res, indx);
    return field;
}

int fieldI(sqlite3_stmt* res, int indx){
    int field = sqlite3_column_int(res, indx);
    return field;
}

int param(int argcount, ...){
    int counter;
    va_list argptr;
    va_start(argptr, argcount);
    char* argcurrent;
    char* sqlnew = malloc(512);
    char* sql = va_arg(argptr, char*);

    for (counter=0; counter <= argcount; counter++) {
        argcurrent =  va_arg(argptr, char *);
        snprintf(sqlnew, sizeof(sqlnew), sql, argcurrent);
    }
    
    int res = update_data(openDB(), sqlnew);
    free(sqlnew);
    return res;
}

int execute_sql_file(){
   return 0; 
}
