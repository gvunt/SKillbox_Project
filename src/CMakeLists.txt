cmake_minimum_required (VERSION 3.26)

set(Src
        "SearchServer.cpp."
        "JsonHandler.cpp"
        "InvertedIndex.cpp"
        "main.cpp"
)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR})
add_executable(Skillbox_Project_ ${Src})

target_link_libraries(Skillbox_Project_ nlohmann_json::nlohmann_json)
target_include_directories(Skillbox_Project_ PUBLIC ${MY_INCLUDE_DIR})