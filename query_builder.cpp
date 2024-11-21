#include "query_builder.h"
#include "database.h"
#include "qsqlquery.h"

/*!
 * \brief This class provides a way to build SQL query strings
 */

query_builder::query_builder() {
    db = database::instance();

    QString sql_query = "";
}

void query_builder::print_query()
{
    qDebug() << this->sql_query;
}


void query_builder::write()
{

}

QSqlQuery query_builder::read()
{
    return db->load_data(this->sql_query);
}

void query_builder::reset_command()
{
    this->sql_query = "$action $target $args";
}

void query_builder::set_action_read()
{
    this->sql_query.replace("$action", "SELECT");
    this->sql_query.replace("$target", "$columns");
    this->sql_query.replace("$args", "FROM $tables");
}

void query_builder::set_action_write()
{
    this->sql_query.replace("$action","INSERT INTO");
    this->sql_query.replace("$target", "$tables");
    this->sql_query.replace("$args", "VALUES $value_args");
}

void query_builder::set_action_write_update()
{
    this->sql_query.append("");
}

void query_builder::set_action_write_delete()
{

}

void query_builder::add_table(QString tables)
{
    this->sql_query.replace("$tables", tables);
}

void query_builder::add_column(QString columns)
{
    this->sql_query.replace("$columns", columns);
}

void query_builder::add_clause(QString clauses)
{

}

void query_builder::add_comma()
{

}
