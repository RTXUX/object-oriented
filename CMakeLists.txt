cmake_minimum_required(VERSION 3.9)
project(object_oriented)

set(CMAKE_CXX_STANDARD 11)

add_executable(object_oriented main.cpp World.cpp World.h Elevator.cpp Elevator.h Scheduler.cpp Scheduler.h Passenger.cpp Passenger.h constants.h)