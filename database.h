#ifndef DATABASE_H
#define DATABASE_H
#include <QSqlDatabase.h>
class database
{
public:
    database();
    static database * instance();
    void insert_data(QSqlDatabase db, QString sql);
    QSqlQuery load_data(QSqlDatabase db, QString sql);
private:
    void init_tables(QSqlDatabase db);

};


#endif // DATABASE_H
