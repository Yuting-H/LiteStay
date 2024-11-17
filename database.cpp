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
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName(QCoreApplication::applicationDirPath() + "/hotel.db");

    if (db.open()) {
        qDebug() << "Connection to database established";
        init_tables(db);
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

void database::init_tables(QSqlDatabase db) {

    //create query object
    QSqlQuery query(db);

    //create table storing employee information

    query.exec("CREATE TABLE IF NOT EXISTS employees (id INTEGER PRIMARY KEY, username VARCHAR(20))");

}
