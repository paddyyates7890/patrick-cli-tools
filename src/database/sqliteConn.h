#include "../sqlite3.h"

#ifndef _TOOLS_DATABASE_
#define _TOOLS_DATABASE_

#define DATABASE "/tools.sqlite"

void closeDB(sqlite3* db, sqlite3_stmt* res);
sqlite3* openDB();
sqlite3_stmt* select_data(sqlite3* db, char* sql);
sqlite3_stmt* step_result(sqlite3_stmt* res);
int update_data(sqlite3* db, char* sql);
char* fieldC(sqlite3_stmt* res, int indx);
int fieldI(sqlite3_stmt* res, int indx);
int paramU(char* sql, ...);
sqlite3_stmt* paramS(char* sql, ...);
int execute_sql_file();
#endif
