#ifndef BOOKING_QUERY_H
#define BOOKING_QUERY_H
#include <QString>
#include "booking_query.h"

class booking_query
{
    query_builder qb;
public:
    booking_query();

    QString get_sql_command();
    void reset_sql_command();
};

#endif // BOOKING_QUERY_H
