#ifndef QUERY_H
#define QUERY_H
#include <QString>
class query
{
private:
    QString sql_command;
public:

    query();
    bool valid_username(QString username);
    void set();
    void print();

};

#endif // QUERY_H
