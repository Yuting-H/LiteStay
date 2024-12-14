#include "room_query.h"
#include "query_builder.h"
#include <QDebug>
#include <QSqlQuery>

room_query::room_query() {
    qb = new query_builder();
}

void room_query::reset_sql_command()
{
    qb->reset_command();
}

QSqlQuery room_query::read_room()
{
    qb->reset_command();
    qb->set_action_read();
    qb->add_column("*");
    qb->add_table("room");
    qb->print_query();
    return qb->read();
}

void room_query::add_room(QString roomid, QString room_type)
{
    qb->reset_command();
    qb->set_action_write();
    qb->add_table("room");
    qb->add_value(roomid, false);
    qb->add_value(room_type, true);
    qb->add_value("", false);
    qb->print_query();
    qb->write();
}

void room_query::delete_room(QString roomid)
{
    qb->reset_command();
    qb->set_action_write_delete();
    qb->add_table("room");
    qb->add_clause("roomid=" + roomid);
    qb->write();
    qb->print_query();
}
