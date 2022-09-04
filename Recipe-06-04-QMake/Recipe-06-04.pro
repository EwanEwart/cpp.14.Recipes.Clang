TEMPLATE = app
CONFIG += console c++17
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
        Car.cpp \
        Motorcycle.cpp \
        Vehicle.cpp \
        main.cpp

DISTFILES += \
  README

HEADERS += \
  Car.h \
  Motorcycle.h \
  Vehicle.h
