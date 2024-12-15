QT       += core gui sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    booking_query.cpp \
    database.cpp \
    login_window.cpp \
    main.cpp \
    main_window.cpp \
    room_query.cpp \
    staff_query.cpp \
    query_builder.cpp \
    window_manager.cpp

HEADERS += \
    booking_query.h \
    database.h \
    login_window.h \
    main_window.h \
    room_query.h \
    staff_query.h \
    query_builder.h \
    window_manager.h

FORMS += \
    login_window.ui \
    main_window.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

DISTFILES +=

RESOURCES +=
