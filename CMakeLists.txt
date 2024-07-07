cmake_minimum_required(VERSION 3.26)
project(Skillbox_Project_)

set(CMAKE_CXX_STANDARD 17)

include(FetchContent)

FetchContent_Declare(json URL https://github.com/nlohmann/json/releases/download/v3.11.3/json.tar.xz)
FetchContent_MakeAvailable(json)

add_executable(Skillbox_Project_ src/main.cpp
        include/JsonHandler.h
        include/InvertedIndex.h
        include/SearchServer.h
        src/JsonHandler.cpp
        src/SearchServer.cpp
        src/InvertedIndex.cpp
        json/config.json
        json/answers.json
        json/requests.json
        files/file1.txt
        files/file2.txt
        files/file3.txt
)

target_link_libraries(Skillbox_Project_ PRIVATE nlohmann_json::nlohmann_json)
