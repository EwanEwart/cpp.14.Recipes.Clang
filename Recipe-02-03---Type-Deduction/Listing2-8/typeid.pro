TEMPLATE = app
CONFIG += console c++14
CONFIG -= app_bundle
CONFIG -= qt

PATH_BOOST = /home/ewan/bordeaux/development/boost_1_61_0
QMAKE_CXXFLAGS += \
  -std=c++14      \


INCLUDEPATH += \
  $$PATH_BOOST/


SOURCES += \
    main.cc
