cmake_minimum_required(VERSION 3.5)

project(Recipe-06-02-A LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(SOURCES
  Vehicle.h
  Vehicle.cpp
  Car.h
  Car.cpp
  Motorcycle.h
  Motorcycle.cpp
)

add_executable(Recipe-06-02-A main.cpp ${SOURCES})
