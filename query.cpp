#include "query.h"
#include "database.h"
#include <QDebug>
query::query() {
    db = database::instance();

    QString sql_command = "";
}


bool query::valid_username(QString username){
    qDebug() << sql_command;
    if (username.compare("admin") == 0) {
        return true;
    }else {
        return false;
    }
}

QString query::get_sql_command() {
    return this->sql_command;
}

void query::reset_sql_command() {
    this->sql_command = "";
}





