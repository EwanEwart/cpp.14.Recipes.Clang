TEMPLATE = app
#CONFIG += console c++17 # dosn't forward c++17
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

QMAKE_CXXFLAGS += \
  -std=c++17

SOURCES += \
  main.cpp

INCLUDEPATH += \
  $$(BOOST_ROOT)

#INCLUDEPATH += /media/ewan/seagate/RED/EE/development/boost_1_71_0

message(BOOST_ROOT = $$(BOOST_ROOT))
