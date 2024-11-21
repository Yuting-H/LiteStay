#include "query.h"
#include "database.h"
#include <QDebug>
#include <QSqlQuery>
query::query() {
    query_builder *qb = new query_builder();
}


bool query::valid_username(QString username){

    QSqlQuery query;


    if (query.exec("SELECT * FROM employees")) {
        qDebug()<< "Login query executed";
        while(query.next()) {
            qDebug() << query.value(0).toString() << query.value(1) << query.value(2) << query.value(3);
        }
        return true;
    }else {
        return false;
    }
}






