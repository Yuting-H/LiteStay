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

/*!
 * \brief booking_query::reset_sql_command
 */
void booking_query::reset_sql_command()
{
    qb.reset_command();
}

/*!
 * \brief booking_query::read_booking
 * \return A QSqlQuery of all the booking records
 */
QSqlQuery booking_query::read_booking()
{
    qb.reset_command();
    qb.set_action_read();
    qb.add_column("*");
    qb.add_table("booking");
    qb.print_query();
    return qb.read();
}

/*!
 * \brief generate a sql query that adds a booking
 */
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

/*!
 * \brief booking_query::delete_booking
 * \param bookid
 */
void booking_query::delete_booking(QString bookid)
{


    qb.reset_command();
    qb.set_action_write_delete();
    qb.add_table("booking");
    qb.add_clause("bookid=" + bookid);
    qb.print_query();
    qb.read();
}

/*!
 * \brief flips the checkedin status of a booking from 0 to a 1, or from 1 to a 0
 * \param bookid
 */
void booking_query::flip_checkin(QString bookid)
{
    qb.reset_command();
    qb.set_action_read();
    qb.add_column("bookid, ischeckedin");
    qb.add_table("booking");
    qb.add_clause("bookid=" + bookid);

    QSqlQuery result = qb.read();
    QString checkin = "0";

    if (result.next()) {
        if (result.value("ischeckedin").toString().compare('0') == 0){
            checkin = "1";
        }
    }

    qb.reset_command();
    qb.set_action_write_update();
    qb.add_table("booking");
    qb.add_column("ischeckedin=" + checkin);
    qb.add_clause("bookid="+bookid);
    qb.print_query();
    qb.write();

}


/*!
 * \brief finds rooms without a booking associated to it during a time frame
 * \param startdate
 * \param enddate
 * \return
 */
QSqlQuery booking_query::find_avaliable_room(QString startdate, QString enddate)
{
    qb.reset_command();
    qb.set_action_read();
    qb.add_column("*");
    qb.add_table("room");
    qb.add_clause("room.roomid NOT IN ("
                  "SELECT booking.roomid FROM booking WHERE NOT ("
                  "booking.enddate < '" + startdate + "' OR booking.startdate > '" + enddate + "'))");
    qb.print_query();
    return qb.read();
}
