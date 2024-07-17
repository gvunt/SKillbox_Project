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

add_library(nlohmann_json INTERFACE)
target_include_directories(nlohmann_json INTERFACE ${CMAKE_SOURCE_DIR}/include/nlohmann)

add_executable(Skillbox_Test ${SOURCES})

target_link_libraries(Skillbox_Test nlohmann_json)
