#ifndef LOGIN_WINDOW_H
#define LOGIN_WINDOW_H
#include "query.h"
#include <QMainWindow>

namespace Ui {
class login_window;
}

class login_window : public QMainWindow
{
    Q_OBJECT

public:
    explicit login_window(QWidget *parent = nullptr);
    ~login_window();

signals:
    void login_request();
    void elevate_privilege();

public slots:
    void received_login_request();

private slots:
    void on_login_button_clicked();

private:
    Ui::login_window *ui;
    query *q;
};

#endif // LOGIN_WINDOW_H
