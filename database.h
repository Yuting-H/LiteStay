#ifndef DATABASE_H
#define DATABASE_H
#include <QSqlDatabase.h>
class database
{
public:
    database();
    static database * instance();
private:
    void init_tables(QSqlDatabase db);

};


#endif // DATABASE_H
