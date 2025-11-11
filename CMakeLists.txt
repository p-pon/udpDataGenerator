cmake_minimum_required(VERSION 3.16)
project(UdpGeneratorGUI LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

find_package(Qt6 REQUIRED COMPONENTS Core Widgets Network)

add_executable(UdpGeneratorGUI
    main.cpp
    MainWindow.cpp
    MainWindow.h
    MainWindow.ui
    UdpDataGenerator.cpp
    UdpDataGenerator.h
    datatypes.h
)

target_link_libraries(UdpGeneratorGUI
    Qt6::Core
    Qt6::Widgets
    Qt6::Network
)
