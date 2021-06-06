cmake_minimum_required(VERSION 3.13)
project(xmltohtml)


set(CMAKE_CXX_STANDARD 11)

add_executable(xmltohtml
        main.cpp
	src/xml.cpp
	library/tinyxml2.cpp
	src/html.cpp)

target_link_libraries (xmltohtml)
