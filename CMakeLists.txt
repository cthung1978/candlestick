cmake_minimum_required(VERSION 3.5)

project(charts VERSION 0.1 LANGUAGES CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Qt5Charts)

# QtCreator supports the following variables for Android, which are identical to qmake Android variables.
# Check https://doc.qt.io/qt/deployment-android.html for more information.
# They need to be set before the find_package( ...) calls below.

find_package(QT NAMES Qt6 Qt5 COMPONENTS Widgets REQUIRED)
find_package(Qt${QT_VERSION_MAJOR} COMPONENTS Widgets REQUIRED)

set(PROJECT_SOURCES
	main.cpp
	candlestickdatareader.cpp
	candlestickdatareader.h
	analysis.cpp
	analysis.h
)

add_executable(charts ${PROJECT_SOURCES})

target_link_libraries(charts PRIVATE Qt5::Widgets Qt5::Charts)

if(QT_VERSION_MAJOR EQUAL 6)
    qt_finalize_executable(charts)
endif()
