#ifndef MAIN_WINDOW_H
#define MAIN_WINDOW_H
#include "booking_query.h"
#include "room_query.h"
#include "staff_query.h"
#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui {
class main_window;
}
QT_END_NAMESPACE

class main_window : public QMainWindow
{
    Q_OBJECT

public:
    main_window(QWidget *parent = nullptr);
    ~main_window();
    void elevate_privilege();

private slots:

    void on_booking_btn_clicked();

    void on_room_btn_clicked();

    void on_staff_btn_clicked();

    void on_add_booking_btn_clicked();

    void on_add_staff_record_btn_clicked();



    void on_search_staff_record_btn_clicked();

    void on_search_room_btn_clicked();

    void on_add_room_btn_clicked();


    void on_add_booking_find_room_btn_clicked();

    void on_add_booking_clicked();


    void on_booking_find_booking_btn_clicked();

private:
    Ui::main_window *ui;
    staff_query *sq;
    room_query *rq;
    booking_query *bq;

    void update_add_room_summary_table();
};
#endif // MAIN_WINDOW_H
