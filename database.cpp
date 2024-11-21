#include "database.h"
#include <QSqlDatabase>
#include <QCoreApplication>
#include <QSqlQuery>
#include <QSqlError>


/*!
 * \brief singleton class providing access to raw data
 */

//global
database *thisdb = nullptr;

/*!
 * \brief private constructor for this singleton class
 */
database::database() {

    db_connection = QSqlDatabase::addDatabase("QSQLITE");

    //set path to database on disk
    db_connection.setDatabaseName(QCoreApplication::applicationDirPath() + "/hotel.db");

    if (db_connection.open()) {
        qDebug() << "Connection to database established";
        init_tables();
    }else {
        qDebug() << "Connection to database failed";
    }
}

/*!
 * \brief gets the reference to the database
 * \return pointer to the database, creates one if not exist
 */
database * database::instance() {
    if (thisdb == nullptr) {
        thisdb = new database();
    }
    return thisdb;
}

/*!
 * \brief initialzes tables that stores the data using SQL
 */
void database::init_tables() {

    //create query object
    QSqlQuery query(db_connection);

    //create table storing employee information

    qDebug() << "creating tables" << query.exec("CREATE TABLE employees (id INTEGER PRIMARY KEY, username VARCHAR(20),password VARCHAR(40), privellege VARCHAR(20))");
    insert_data( "INSERT INTO employees VALUES(0, 'admin', 'password', 'admin')");

}

/*!
 * \brief database::insert_data
 * \param db
 * \param sql
 */
void database::insert_data( QString sql) {

    QSqlQuery query_insert_data(db_connection);


    //excute sql, if error print error msg
    if(query_insert_data.exec(sql)) {

    }else {
        qDebug()<< "Error inserting: " << query_insert_data.lastError();
    }
}

/*!
 * \brief database::select_data
 * \param db
 * \param sql
 * \return
 */
QSqlQuery database::load_data(QString sql) {

    //execute sql on db
    QSqlQuery query_load_data(db_connection);

    //excute sql, if error print error msg
    if(query_load_data.exec(sql)) {

    }else {
        qDebug() << query_load_data.lastError();
    }

    return query_load_data;
}
