cmake_minimum_required(VERSION 3.5)

project(MiscTest VERSION 0.1 LANGUAGES CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_BUILD_TYPE DEBUG)
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# find qt
find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Widgets)

if(QT_FOUND)
    message("QT_VERSION_MAJOR = ${QT_VERSION_MAJOR}")
    message("QT_VERSION_MAJOR = ${QT_VERSION_MINOR}")
    message("QT_VERSION_PATCH = ${QT_VERSION_PATCH}")
    message("Qt${QT_VERSION_MAJOR}_DIR = ${Qt${QT_VERSION_MAJOR}_DIR}")
endif(QT_FOUND)

if(${QT_VERSION_MAJOR} GREATER_EQUAL 6)
    find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Widgets Core5Compat)
endif()
# find_package(QT NAMES Qt5 COMPONENTS Core Widgets REQUIRED)
# find_package(Qt5 COMPONENTS Core Widgets REQUIRED)
set(PROJECT_SOURCES
    son.h
    son.cpp
    father.h
    father.cpp
    main.cpp
    mainwindow.cpp
    mainwindow.h
    mainwindow.ui)

if(${QT_VERSION_MAJOR} GREATER_EQUAL 6)
    qt_add_executable(MiscTest
        MANUAL_FINALIZATION
        ${PROJECT_SOURCES}
    )
else()
    if(ANDROID)
        add_library(MiscTest SHARED
            ${PROJECT_SOURCES}
        )
    else()
        add_executable(MiscTest
            ${PROJECT_SOURCES}
        )
    endif()
endif()

target_link_libraries(MiscTest PRIVATE
    Qt${QT_VERSION_MAJOR}::Widgets)

if(${QT_VERSION_MAJOR} GREATER_EQUAL 6)
    target_link_libraries(MiscTest PRIVATE
        Qt${QT_VERSION_MAJOR}::Core5Compat)
else()
    target_link_libraries(MiscTest PRIVATE
        Qt${QT_VERSION_MAJOR}::Core)
endif()

if(QT_VERSION_MAJOR EQUAL 6)
    qt_finalize_executable(MiscTest)
endif()
