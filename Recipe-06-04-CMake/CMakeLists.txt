cmake_minimum_required(VERSION 3.5)

project(Recipe-06-04-CMake LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(SOURCES
  Vehicle.h
  Vehicle.cpp
  Car.h Car.cpp
  Motorcycle.h
  Motorcycle.cpp
  Tricycle.h
  Tricycle.cpp
  )

add_executable(app main.cpp ${SOURCES})
