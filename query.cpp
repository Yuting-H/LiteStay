#include "query.h"
#include "database.h"
#include <QDebug>
query::query() {
    query_builder *qb = new query_builder();
}


bool query::valid_username(QString username){

    if (username.compare("admin") == 0) {
        return true;
    }else {
        return false;
    }
}






