cmake_minimum_required(VERSION 3.21)

project(MainWin_lib VERSION 0.1 LANGUAGES CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_subdirectory(InputDataWindow)

set(SOURCE_ONE  Observers/Tree.h
                         Observers/Tree.cpp
                         Observers/BinaryTree.h Observers/BinaryTree.cpp
                         StructureData/TreeBuilder.h
                         StructureData/AvlBuilder.h StructureData/AvlBuilder.cpp
                         Stream/Author.h Stream/Author.cpp
                         Stream/Publisher.h Stream/Publisher.cpp
                         Stream/BufferData.h
                         )


set(SOURCE_TWO  UiWindows/HistorySearch.h
                UiWindows/HistorySearch.cpp
                UiWindows/historysearch.ui
                UiWindows/ListTablesWithFoundData.h
                UiWindows/ListTablesWithFoundData.cpp
                UiWindows/SearchPublisherWindow.h
                UiWindows/SearchPublisherWindow.cpp
                UiWindows/searchpublisherwindow.ui
                UiWindows/TableAboutAuthor.h
                UiWindows/TableAboutAuthor.cpp
                UiWindows/TableAllPublisherWindow.h
                UiWindows/TableAllPublisherWindow.cpp
                UiWindows/tableallpublisherwindow.ui
                UiWindows/WhatInputWindow.h
                UiWindows/WhatInputWindow.cpp
                UiWindows/WhatInputWindow.ui
                UiWindows/MainWindow.h
                UiWindows/MainWindow.cpp
                UiWindows/mainwindow.ui)

find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Core Widgets Xml )
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Core Widgets Xml )


add_library(MainWin_lib STATIC ${SOURCE_ONE} ${SOURCE_TWO})
target_include_directories(MainWin_lib PRIVATE
                               "${CMAKE_CURRENT_SOURCE_DIR}/InputDataWindow"
                               "${CMAKE_CURRENT_SOURCE_DIR}/SearchPublisherWindow"
                               "${CMAKE_CURRENT_SOURCE_DIR}/Commands"
                               "${CMAKE_CURRENT_SOURCE_DIR}/Observers"
                               "${CMAKE_CURRENT_SOURCE_DIR}/StructureData"
                               "${CMAKE_CURRENT_SOURCE_DIR}/Stream"
                               "${CMAKE_CURRENT_SOURCE_DIR}/UiWindows")

target_link_libraries(MainWin_lib InputData_lib Qt${QT_VERSION_MAJOR}::Widgets
                                                Qt${QT_VERSION_MAJOR}::Core
                                                Qt${Qt_VERSION_MAJOR}::Xml)


