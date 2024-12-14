#ifndef ROOM_QUERY_H
#define ROOM_QUERY_H

#include "qsqlquery.h"
#include "query_builder.h"
class room_query
{
    query_builder* qb;
public:
    room_query();

    QString get_sql_command();
    void reset_sql_command();

    QSqlQuery read_room();
    void add_room(QString roomid, QString room_type);
    void delete_room(int roomid);
};

#endif // ROOM_QUERY_H
