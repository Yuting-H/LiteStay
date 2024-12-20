#include "staff_query.h"
#include <QDebug>
#include <QSqlQuery>
staff_query::staff_query() {
    query_builder *qb = new query_builder();
}

void staff_query::reset_sql_command()
{
    this->qb.reset_command();
}

/*!
 * \brief checks if the supplied username and password matches a record of a staff in the database
 * \param username
 * \param password
 * \return
 */
bool staff_query::valid_login_info(QString username, QString password){

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
bool staff_query::user_is_admin(QString username)
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

/*!
 * \brief adds a staff record into the database
 * \param id is a unique
 * \param username
 * \param password
 * \param priv
 */
void staff_query::add_staff(QString id, QString username, QString password, QString priv)
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

QSqlQuery staff_query::read_staff()
{
    qb.reset_command();
    qb.set_action_read();
    qb.add_column("*");
    qb.add_table("employee");
    qb.print_query();
    return qb.read();
}

void staff_query::delete_staff(QString id) {
    qb.reset_command();
    qb.set_action_write_delete();
    qb.add_table("employee");
    qb.add_clause("id=" + id);
    qb.write();
    qb.print_query();
}






