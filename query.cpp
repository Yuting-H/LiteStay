#include "query.h"
#include "database.h"
#include <QDebug>
#include <QSqlQuery>
query::query() {
    query_builder *qb = new query_builder();
}

void query::reset_sql_command()
{
    this->qb.reset_command();
}


bool query::valid_login_info(QString username, QString password){

    qb.reset_command();
    qb.set_action_read();
    qb.add_table("employee");
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

/*!
 * \brief checks if user has admin priveileges
 * \param username of the user
 * \return true if user is an admin
 */
bool query::user_is_admin(QString username)
{
    qb.reset_command();
    qb.set_action_read();
    qb.add_table("employee");
    qb.add_column("privilege");
    qb.add_clause("username='" +username + "'");
    qb.print_query();
    QSqlQuery returned_query = qb.read();

    //check existence of matching record
    while (returned_query.next()) {

        if(returned_query.value("privilege").toString().compare("admin") == 0){
            return true;
        }
    }
    return false;   //no matching record
}

void query::add_staff(QString id, QString username, QString password, QString priv)
{
    qb.reset_command();
    qb.set_action_write();
    qb.add_table("employee");
    qb.add_value(id, false);
    qb.add_value(username, true);
    qb.add_value(password, true);
    qb.add_value(priv, true);
    qb.add_value("" , false); //send flag to finish adding values
    qb.write();
    qb.print_query();

}

QSqlQuery query::read_staff()
{
    qb.reset_command();
    qb.set_action_read();
    qb.add_column("*");
    qb.add_table("employee");
    qb.print_query();
    return qb.read();
}







