cmake_minimum_required(VERSION 3.10)

project(Skillbox_Project)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

include_directories(include)

set(SOURCES
        src/main.cpp
        src/JsonHandler.cpp
        src/InvertedIndex.cpp
        src/SearchServer.cpp
)

add_library(nlohmann_json INTERFACE)
target_include_directories(nlohmann_json INTERFACE include/nlohmann)

add_executable(Skillbox_Project ${SOURCES})

target_link_libraries(Skillbox_Project nlohmann_json)


