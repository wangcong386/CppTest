cmake_minimum_required(VERSION 3.5)

project(
  MiscTest
  VERSION 0.1
  LANGUAGES CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOUIC_SEARCH_PATHS ${CMAKE_CURRENT_SOURCE_DIR}/ui)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
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

message("CMAKE_CURRENT_SOURCE_DIR" ${CMAKE_CURRENT_SOURCE_DIR})
file(GLOB HEADER_FILES ${CMAKE_CURRENT_SOURCE_DIR}/include/*.h)
file(GLOB SRC_FILES ${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp)
file(GLOB UI_FILES ${CMAKE_CURRENT_SOURCE_DIR}/ui/*.ui)

message("SRC_FILES" ${SRC_FILES})

add_subdirectory(qcustomplot)

if(${QT_VERSION_MAJOR} GREATER_EQUAL 6)
  qt_add_executable(MiscTest MANUAL_FINALIZATION ${HEADER_FILES} ${SRC_FILES})
else()
  if(ANDROID)
    add_library(MiscTest SHARED ${SRC_FILES})
  else()
    add_executable(MiscTest ${SRC_FILES})
  endif()
endif()

target_include_directories(MiscTest PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)

target_link_libraries(MiscTest PRIVATE Qt${QT_VERSION_MAJOR}::Widgets
                                       QCustomPlot)

if(${QT_VERSION_MAJOR} GREATER_EQUAL 6)
  target_link_libraries(MiscTest PRIVATE Qt${QT_VERSION_MAJOR}::Core5Compat)
else()
  target_link_libraries(MiscTest PRIVATE Qt${QT_VERSION_MAJOR}::Core)
endif()

if(QT_VERSION_MAJOR EQUAL 6)
  qt_finalize_executable(MiscTest)
endif()
