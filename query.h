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

    QString get_sql_command();
    void reset_sql_command();



    bool valid_login_info(QString username, QString password);
    bool user_is_admin(QString username);

    void add_staff(QString id, QString username, QString password, QString priv);
    QSqlQuery read_staff();



};

#endif // QUERY_H
