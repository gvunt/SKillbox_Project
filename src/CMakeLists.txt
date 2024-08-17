project(Skillbox_Test)

include_directories(${CMAKE_SOURCE_DIR}/include)

set(SOURCES
        main.cpp
        JsonHandler.cpp
        InvertedIndex.cpp
        SearchServer.cpp
        ../include/InvertedIndex.h
        ../include/JsonHandler.h
        ../include/SearchServer.h
)

include(FetchContent)

FetchContent_Declare(json URL https://github.com/nlohmann/json/releases/download/v3.11.3/json.tar.xz)
FetchContent_MakeAvailable(json)

target_link_libraries(foo PRIVATE nlohmann_json::nlohmann_json)

add_library(nlohmann_json INTERFACE)
target_include_directories(nlohmann_json INTERFACE ${CMAKE_SOURCE_DIR}/include/nlohmann)

add_executable(Skillbox_Test ${SOURCES})

target_link_libraries(Skillbox_Test nlohmann_json)
