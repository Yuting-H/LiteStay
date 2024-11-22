#ifndef QUERY_BUILDER_H
#define QUERY_BUILDER_H
#include "database.h"
#include "QString"

/*!
 * \brief The query_builder class provides functions that
 * builds and executes sql queries
 */
class query_builder
{
private:
    QString sql_query;
    database *db;

public:
    query_builder();

    void print_query();
    void write();
    QSqlQuery read();
    void reset_command();
    void set_action_read();
    void set_action_write();
    void set_action_write_update();
    void set_action_write_delete();
    void add_table(QString tables);
    void add_column(QString columns);
    void add_clause(QString clauses);

};

#endif // QUERY_BUILDER_H
