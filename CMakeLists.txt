cmake_minimum_required(VERSION 3.21)


project(LivesWonderfulPeople VERSION 0.1 LANGUAGES CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)


add_subdirectory(Windows)
find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Core Xml Core5Compat)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Core Xml Core5Compat)

set(PROJECT_SOURCES
        main.cpp
        Windows/Commands/SearchInputDataCommand.cpp
        Windows/Commands/SearchInputDataCommand.h
        Windows/Commands/CheckInputDataCommand.h
        Windows/Commands/CheckInputDataCommand.cpp
        Windows/Commands/AddWorkAuthorCommand.cpp
        Windows/Commands/AddWorkAuthorCommand.h
        Windows/Commands/WorkingWithDataLinker.cpp
        Windows/Commands/WorkingWithDataLinker.h
        Windows/UiWindows/Window.cpp
        Windows/UiWindows/Window.h
        Windows/UiWindows/Warning.cpp
        Windows/UiWindows/Warning.h
        Windows/Commands/Commands.h
        Windows/Commands/ManagerLinkerCommand.cpp   
        Windows/Commands/ManagerLinkerCommand.h
        Windows/Commands/OpenWinCommand.cpp
        Windows/Commands/OpenWinCommand.h
        Windows/Commands/HideWinCommand.cpp
        Windows/Commands/HideWinCommand.h
)

qt6_add_resources(RCCFILE "${CMAKE_CURRENT_SOURCE_DIR}/Style/MyStyle.qrc"
                          "${CMAKE_CURRENT_SOURCE_DIR}/Icons/MyIcons.qrc"
                          "${CMAKE_CURRENT_SOURCE_DIR}/DataXml.qrc")

if(WIN32)
    add_executable(LivesWonderfulPeople WIN32 ${PROJECT_SOURCES} ${RCCFILE})
else()
    add_executable(LivesWonderfulPeople ${PROJECT_SOURCES} ${RCCFILE})
endif()

target_include_directories(LivesWonderfulPeople PRIVATE "${CMAKE_CURRENT_SOURCE_DIR}/Windows"
                                                       "${CMAKE_CURRENT_SOURCE_DIR}/Windows/Observers"
                                                       "${CMAKE_CURRENT_SOURCE_DIR}/Windows/Stream"
                                                       "${CMAKE_CURRENT_SOURCE_DIR}/Windows/UiWindows")

target_link_libraries(LivesWonderfulPeople MainWin_lib Qt${QT_VERSION_MAJOR}::Core
                                                       Qt${QT_VERSION_MAJOR}::Xml
                                                       Qt${QT_VERSION_MAJOR}::Core5Compat)

