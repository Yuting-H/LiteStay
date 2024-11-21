#ifndef QUERY_BUILDER_H
#define QUERY_BUILDER_H
#include "database.h"
#include "QString"

class query_builder
{
private:
    QString sql_command;
    database *db;

public:
    query_builder();
};

#endif // QUERY_BUILDER_H
