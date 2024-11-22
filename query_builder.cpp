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
    db->insert_data(this->sql_query);
}

QSqlQuery query_builder::read()
{
    return db->load_data(this->sql_query);
}

/*
 * The following functions are used to generate valid sql commands
 * based on a set of context-free rewrite rules where,
 * $ denotes a non-terminal string and will be rewritted to terminal
 * or other non-terminal strings to produce a valid sql command
 */

/*!
 * \brief resets the command
 * $action = the action the command is going to do
 * $target = the entity the action is acting on, depends on the action, this can be a table, column, or rows in a table
 * $args = the value needed to apply said action
 */
void query_builder::reset_command()
{
    this->sql_query = "$action $target $args";
}

/*!
 * \brief set command to read from the db
 */
void query_builder::set_action_read()
{
    this->sql_query.replace("$action", "SELECT");
    this->sql_query.replace("$target", "$columns"); //names of columns
    this->sql_query.replace("$args", "FROM $tables");   //names of tables
}

/*!
 * \brief set the command to write to db
 */
void query_builder::set_action_write()
{
    this->sql_query.replace("$action","INSERT INTO");
    this->sql_query.replace("$target", "$tables");
    this->sql_query.replace("$args", "VALUES($value_args)");
}

/*!
 * \brief set the command to update records in db
 */
void query_builder::set_action_write_update()
{
    this->sql_query.replace("$action", "UPDATE");
    this->sql_query.replace("$target", "$tables");
    this->sql_query.replace("$args", "SET $column_value_pairs");
}

/*!
 * \brief set the command to delete records from the db
 */
void query_builder::set_action_write_delete()
{
    this->sql_query.replace("$action", "DELETE FROM");
    this->sql_query.replace("$target", "$tables");
    this->sql_query.replace("$args", ""); //no args for delete operation, WHERE clauses should be used instead
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
    this->sql_query.append(" WHERE " + clauses);
}


