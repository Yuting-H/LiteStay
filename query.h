#ifndef QUERY_H
#define QUERY_H
#include <QString>
#include "database.h"
class query
{
private:
    QString sql_command;
    database *db;
public:

    query();
    bool valid_username(QString username);
    QString get_sql_command();
    void reset_sql_command();

};

#endif // QUERY_H
