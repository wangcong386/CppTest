cmake_minimum_required(VERSION 3.5)

project(QtTest VERSION 0.1 LANGUAGES CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_BUILD_TYPE DEBUG)
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(QT NAMES Qt5 COMPONENTS Core Widgets REQUIRED)
find_package(Qt5 COMPONENTS Core Widgets REQUIRED)

set(PROJECT_SOURCES
    son.h
    son.cpp
    father.h
    father.cpp
    main.cpp
    mainwindow.cpp
    mainwindow.h
    mainwindow.ui)

add_executable(QtTest
    ${PROJECT_SOURCES})

target_link_libraries(QtTest PRIVATE
    Qt5::Widgets
    Qt5::Core)
