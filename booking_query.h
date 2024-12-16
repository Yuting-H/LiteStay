#ifndef BOOKING_QUERY_H
#define BOOKING_QUERY_H
#include <QString>
#include "query_builder.h"

class booking_query
{
    query_builder qb;
public:
    booking_query();

    QString get_sql_command();
    void reset_sql_command();

    QSqlQuery read_booking();
    void add_booking(QString ischeckedin, QString roomid, QString guest_first_name, QString guest_last_name, QString start_date, QString end_date);
    void delete_booking(QString bookid);

    QSqlQuery find_avaliable_room(QString startdate, QString enddate);


    void test();
};

#endif // BOOKING_QUERY_H
