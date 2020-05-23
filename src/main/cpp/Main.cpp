#include <stddef.h>
#include <stdio.h>
#include "sqlite3.h"

int main() {
     int ret = 0;
     sqlite3* db = NULL;
     sqlite3_stmt* query = NULL;
     char *zErrMsg = 0;
     //open the database
     if (SQLITE_OK != (ret = sqlite3_open_v2("test.db", &db, SQLITE_OPEN_READWRITE | SQLITE_OPEN_CREATE, NULL)))
     {
        return -1;
     }
    ret = sqlite3_prepare_v2(db, "SELECT SQLITE_VERSION()", -1, &query, 0);
    if (ret != SQLITE_OK) {
        return -1;
    }
    ret = sqlite3_step(query);
    if (ret == SQLITE_ROW) {
            printf("%s\n", sqlite3_column_text(query, 0));
    }
    sqlite3_finalize(query);
    sqlite3_close(db);
    return 0;
}

