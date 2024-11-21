#ifndef QUERY_H
#define QUERY_H
#include <QString>
#include "query_builder.h"
class query
{
private:
    query_builder qb;
public:

    query();
    bool valid_login_info(QString username, QString password);
    QString get_sql_command();
    void reset_sql_command();

};

#endif // QUERY_H
