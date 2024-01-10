cmake_minimum_required(VERSION 3.21)

project(InputData_lib LANGUAGES CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Core Widgets)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Core Widgets)

set(PROJECT_FILES InputDataWindow.cpp
                  InputDataWindow.h
                  InputDataWindow.ui)

add_library(InputData_lib STATIC ${PROJECT_FILES})
target_include_directories(InputData_lib PUBLIC "../"
                                                 "../Commands"
                                                 "../UiWindows")


target_link_libraries(InputData_lib PRIVATE Qt${QT_VERSION_MAJOR}::Widgets
                                            Qt${QT_VERSION_MAJOR}::Core)

target_compile_definitions(InputData_lib PRIVATE ADDESSAYWINDOW_LIBRARY)
