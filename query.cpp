#include "query.h"
#include "database.h"
#include <QDebug>
#include <QSqlQuery>
query::query() {
    query_builder *qb = new query_builder();
}


bool query::valid_login_info(QString username, QString password){


    qb.reset_command();
    qb.set_action_read();
    qb.add_table("employees");
    qb.add_column("username, password");
    qb.print_query();
    QSqlQuery returned_query = qb.read();


    //check query has correctly executed
    if (returned_query.exec()) {

        //check existence of matching record
        while (returned_query.next()) {

            if(returned_query.value("username").toString().compare(username) == 0 &&
                returned_query.value("password").toString().compare(password) == 0 ){
                return true;
            }
        }
        return false;   //no matching record

    }else {
        qDebug() << "error querying while validating login info";
        return false;
    }
}






