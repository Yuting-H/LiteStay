include(gtest_dependency.pri)

TEMPLATE = app
CONFIG += console c++14
CONFIG -= app_bundle
CONFIG += thread
CONFIG -= qt

SOURCES += \
        ../tst_database.cpp \
        main.cpp \
        mockdatabase.cpp \
        tst_login_window.cpp

HEADERS += \
    mockdatabase.h
