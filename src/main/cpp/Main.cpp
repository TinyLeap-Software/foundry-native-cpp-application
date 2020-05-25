#include <stddef.h>
#include <stdio.h>
#include "sqlite3.h"
//logger
#include "spdlog/spdlog.h"
#include "spdlog/sinks/daily_file_sink.h"


int main() {
//     //create a daily logger. a new file is created everyday at logs/app-<date>.log at 00:00 hours.
//     auto logger = spdlog::daily_logger_mt("daily_logger", "logs/app.log", 00, 00);

     // Set the logger pattern.
     // [Date] [time] [level] [thread name] [Filename:LineNumber] Log message
     spdlog::set_pattern("%^[%Y.%m.%d] [%H:%M:%S] [%n:%l] [%t] [%s:%#] %v%$");
     spdlog::set_level(spdlog::level::debug);

     spdlog::info("Starting your CPP Application.");
     int ret = 0;
     sqlite3* db = NULL;
     sqlite3_stmt* query = NULL;
     char *zErrMsg = 0;

     SPDLOG_INFO("Opening the Database");
     if (SQLITE_OK != (ret = sqlite3_open_v2("test.db", &db, SQLITE_OPEN_READWRITE | SQLITE_OPEN_CREATE, NULL)))
     {
        return -1;
     }
    ret = sqlite3_prepare_v2(db, "SELECT SQLITE_VERSION()", -1, &query, 0);
    if (ret != SQLITE_OK) {
        SPDLOG_CRITICAL("Could not get version");
        return -1;
    }
    ret = sqlite3_step(query);
    if (ret == SQLITE_ROW) {
            SPDLOG_INFO("The SQLite version you're using is: {}",sqlite3_column_text(query, 0));
    }
    sqlite3_finalize(query);
    SPDLOG_INFO("Closing the Database");
    sqlite3_close(db);

    return 0;
}

