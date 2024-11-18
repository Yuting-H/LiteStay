#include "query.h"
#include "database.h"

query::query() {
    database *db = database::instance();

    QString sql_command = "";
}


bool query::valid_username(QString username){
    if (username.compare("admin") == 0) {
        return true;
    }else {
        return false;
    }
}


