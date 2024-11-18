#include "query.h"
#include "database.h"
#include <QDebug>
query::query() {
    database *db = database::instance();

    QString sql_command = "";
}


bool query::valid_username(QString username){
    set();
    qDebug() << sql_command;
    if (username.compare("admin") == 0) {
        return true;
    }else {
        return false;
    }
}

void query::set() {
    this->sql_command = "asdouh";
}

void query::print() {
    qDebug() << this->sql_command;
}



