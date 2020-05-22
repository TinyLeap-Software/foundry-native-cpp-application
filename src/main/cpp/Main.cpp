#include <stddef.h>

#include "sqlite3.h"

int main() {
     int ret = 0;
     sqlite3* pDb = NULL;
     sqlite3_stmt* query = NULL;
     char *zErrMsg = 0;
     if (SQLITE_OK != (ret = sqlite3_open_v2("test.db", &pDb, SQLITE_OPEN_READWRITE | SQLITE_OPEN_CREATE, NULL)))
     {
       return -1;
     }

    return 0;
}