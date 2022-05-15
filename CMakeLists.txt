cmake_minimum_required(VERSION 3.5)

project(QtTest VERSION 0.1 LANGUAGES CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_BUILD_TYPE DEBUG)
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(QT NAMES Qt6 Qt5 COMPONENTS Core Widgets REQUIRED)
find_package(Qt${QT_VERSION_MAJOR} COMPONENTS Core Widgets REQUIRED)
#find_package(Armadillo REQUIRED)
#find_package(PythonLibs REQUIRED)

include_directories(
    ${PYTHON_INCLUDE_DIRS})

set(PROJECT_SOURCES
        base.h
        base.cpp
        main.cpp
        mainwindow.cpp
        mainwindow.h
        mainwindow.ui)

if(${QT_VERSION_MAJOR} GREATER_EQUAL 6)
    qt_add_executable(QtTest
        MANUAL_FINALIZATION
        ${PROJECT_SOURCES})
else()
        add_executable(QtTest
            ${PROJECT_SOURCES})
endif()

target_link_libraries(QtTest PRIVATE
#    ${PYTHON_LIBRARIES}
    Qt${QT_VERSION_MAJOR}::Widgets
    Qt${QT_VERSION_MAJOR}::Core)

set_target_properties(QtTest PROPERTIES
    MACOSX_BUNDLE_GUI_IDENTIFIER my.example.com
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR})

if(QT_VERSION_MAJOR EQUAL 6)
    qt_finalize_executable(QtTest)
endif()
