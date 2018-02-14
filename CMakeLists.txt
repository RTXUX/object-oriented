cmake_minimum_required(VERSION 3.9)
project(elevator)

set(CMAKE_CXX_STANDARD 11)

if (MINGW)
    set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -static-libgcc -static -fexec-charset=gbk")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -static-libgcc -static-libstdc++ -static -fexec-charset=gbk")
    set(CMAKE_SHARED_LIBRARY_LINK_C_FLAGS"${CMAKE_SHARED_LIBRARY_LINK_C_FLAGS} -static-libgcc -s")
    set(CMAKE_SHARED_LIBRARY_LINK_CXX_FLAGS "${CMAKE_SHARED_LIBRARY_LINK_CXX_FLAGS} -static-libgcc -static-libstdc++ -s")
endif ()

add_executable(elevator main.cpp World.cpp World.h Elevator.cpp Elevator.h Scheduler.cpp Scheduler.h Passenger.cpp Passenger.h constants.h)