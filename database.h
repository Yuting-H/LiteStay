#ifndef DATABASE_H
#define DATABASE_H
#include <QSqlDatabase.h>
class database
{
public:
    database();
    static database * instance();
    void insert_data(QString sql);
    QSqlQuery load_data(QString sql);
private:
    QSqlDatabase db_connection;
    void init_tables();

};


#endif // DATABASE_H
