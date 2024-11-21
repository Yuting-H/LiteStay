#include "query_builder.h"
#include "database.h"

/*!
 * \brief This class provides a way to build SQL query strings
 */

query_builder::query_builder() {
    db = database::instance();

    QString sql_command = "";
}

void query_builder::write()
{

}

void query_builder::read()
{

}

void query_builder::reset_command()
{
    this->sql_command = "";
}

void query_builder::set_action_read()
{
    this->sql_command.append("SELECT ");
}

void query_builder::set_action_write()
{
    this->sql_command.append("INSERT INTO");
}

void query_builder::set_action_write_update()
{
    this->sql_command.append("");
}

void query_builder::set_action_write_delete()
{

}

void query_builder::add_table(QString table)
{

}

void query_builder::add_column(QString column)
{

}

void query_builder::add_clause(QString clause)
{

}

void query_builder::add_comma()
{

}
