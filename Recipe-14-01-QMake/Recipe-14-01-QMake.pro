TEMPLATE = app
#CONFIG += console c++17
CONFIG += c++17
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
        main.cpp

LIBS += \
  -lglfw3 \
  -lGL \
  -lGLU \
  -lGLEW \
  -lrt \
  -lm \
  -ldl \
  -lX11 \
  -lpthread \
  -lxcb \
  -lXau \
  -lXdmcp \
  -lOpenGL

