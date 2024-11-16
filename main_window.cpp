#include "main_window.h"
#include "ui_main_window.h"
#include <QDebug>

main_window::main_window(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::main_window)
{
    ui->setupUi(this);
    setFixedSize(1024, 578);
}

main_window::~main_window()
{
    delete ui;
}

//Enables buttons that let the user change employee and room info
void main_window::elevate_privilege() {

}


void main_window::on_booking_btn_clicked()
{
    ui->query_window->setCurrentIndex(0);
}


void main_window::on_room_btn_clicked()
{
    ui->query_window->setCurrentIndex(1);
}


void main_window::on_staff_btn_clicked()
{
    ui->query_window->setCurrentIndex(2);
}

