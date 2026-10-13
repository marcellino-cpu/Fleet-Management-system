cmake_minimum_required(VERSION 4.3)
project(untitled1)

set(CMAKE_CXX_STANDARD 20)

add_executable(untitled1 main.cpp
        Vehicle.cpp
        Vehicle.h
        Car.cpp
        Car.h
        Engine.cpp
        Engine.h
        Battery.cpp
        Battery.h
        Motorcycle.cpp
        Motorcycle.h
        Fleet_Management_System.cpp
        Fleet_Management_System.h)
