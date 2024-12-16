#include "booking_query.h"
#include <QDebug>
#include <QSqlQuery>
/*!
 * \brief This class handles all booking queries
 */
booking_query::booking_query() {
    query_builder *qb = new query_builder();
}

QString booking_query::get_sql_command()
{

}

void booking_query::reset_sql_command()
{
    qb.reset_command();
}

QSqlQuery booking_query::read_booking()
{
    qb.reset_command();
    qb.set_action_read();
    qb.add_column("*");
    qb.add_table("booking");
    qb.print_query();
    return qb.read();
}

void booking_query::add_booking(QString ischeckedin, QString roomid, QString guest_first_name, QString guest_last_name, QString start_date, QString end_date)
{
    qb.reset_command();
    qb.set_action_write();
    qb.add_table("booking");
    qb.add_value("null", false); //omitting bookid, sqlite will auto-assign
    qb.add_value(ischeckedin, false);
    qb.add_value(roomid, false);
    qb.add_value(guest_first_name, true);
    qb.add_value(guest_last_name, true);
    qb.add_value(start_date, true);
    qb.add_value(end_date, true);
    qb.add_value("", false);
    qb.write();
    qb.print_query();
}

void booking_query::delete_booking(QString bookid)
{
    qb.reset_command();
    qb.set_action_write_delete();
    qb.add_table("booking");
    qb.add_clause("bookid=" + bookid);
    qb.print_query();
    qb.read();
}

//delete this in prod
void booking_query::test() {
    qb.reset_command();
    qb.set_action_read();
    qb.add_column("room.roomid");
    qb.add_table("room, booking");

    qb.print_query();
}

QSqlQuery booking_query::find_avaliable_room(QString startdate, QString enddate)
{
    qb.reset_command();
    qb.set_action_read();
    qb.add_column("room.roomid");
    qb.add_table("room");
    qb.add_clause("room.roomid NOT IN ("
                  "SELECT booking.roomid FROM booking WHERE NOT ("
                  "booking.enddate < '" + startdate + "' OR booking.startdate > '" + enddate + "'))");
    qb.print_query();
    return qb.read();
}
