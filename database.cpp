#include "database.h"
#include <QSqlDatabase>
#include <QCoreApplication>
#include <QSqlQuery>
#include <QSqlError>
#include <QFile>
#include <QDir>
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

    query.exec("CREATE TABLE employee (id INTEGER PRIMARY KEY, "
               "username VARCHAR(20) UNIQUE,"
               "password VARCHAR(40), "
               "privilege VARCHAR(20))");

    //insert default users
    insert_data("INSERT INTO employee VALUES(0, 'admin', '', 'admin')");
    insert_data("INSERT INTO employee VALUES(1, 'defaultuser', '', 'user')");

    //create table storing room information
    query.exec("CREATE TABLE room (roomid INTEGER PRIMARY KEY, roomtype VARCHAR(40))");
    insert_data("INSERT INTO room VALUES(0, 'example room type')");
    insert_data("INSERT INTO room VALUES(101, 'Basic 2 Bed')");

    //create table storing
    query.exec("CREATE TABLE booking (bookid INTEGER PRIMARY KEY,"
               "ischeckedin boolean,"
               "roomid INTEGER,"
               "guestfirstname VARCHAR(40),"
               "guestlastname VARCHAR(40),"
               "startdate DATE,"
               "enddate DATE,"
               " FOREIGN KEY (roomid) REFERENCES room(roomid))");
    insert_data("INSERT INTO booking VALUES(0, false, 101, 'John', 'Doe', '2024-01-09', '2024-01-10') ");
    insert_data("INSERT INTO booking VALUES(1, true, 102, 'Mary', 'Sue', '2024-11-01', '2024-11-05')");
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
        qDebug() << "databse.cpp, error while load data: " << query_load_data.lastError();
    }

    return query_load_data;
}
