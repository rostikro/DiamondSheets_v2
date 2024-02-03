cmake_minimum_required(VERSION 3.26)
project(DiamondSheets)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

list(APPEND CMAKE_MODULE_PATH ${CMAKE_CURRENT_SOURCE_DIR}/cmake)

# Specify the path to QT msvc here
# For example: C:/Qt/6.6.1/msvc2019_64
set(CMAKE_PREFIX_PATH "C:/Qt/6.6.1/msvc2019_64")

find_package(Qt6 COMPONENTS
        Core
        Gui
        Widgets
        Network
        NetworkAuth
        REQUIRED)

set(ANTLR4_WITH_STATIC_CRT OFF)

include(ExternalAntlr4Cpp)
include_directories(${ANTLR4_INCLUDE_DIRS})

set(ANTLR_EXECUTABLE ${CMAKE_CURRENT_SOURCE_DIR}/tools/antlr-4.13.1-complete.jar)
find_package(ANTLR REQUIRED)

add_subdirectory(src)
