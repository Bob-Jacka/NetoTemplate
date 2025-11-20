cmake_minimum_required(VERSION 3.31)
project(NetoTemplate)

set(CMAKE_CXX_STANDARD 20)

add_executable(NetoTemplate

        firstTask/main.cpp

        #        secondTask/main.cpp
        #        secondTask/Table.hpp

        #        thirdTask/main.cpp

        libio.cppm
)

target_sources(NetoTemplate
        PUBLIC
        FILE_SET all_my_modules TYPE CXX_MODULES FILES
        libio.cppm
)