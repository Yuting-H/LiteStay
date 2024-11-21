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
    void write();
    void read();
    void reset_command();
    void set_action_read();
    void set_action_write();
    void set_action_write_update();
    void set_action_write_delete();
    void add_table(QString table);
    void add_column(QString column);
    void add_clause(QString clause);
    void add_comma();
};

#endif // QUERY_BUILDER_H
