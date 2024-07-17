project(Skillbox_Test)

include(FetchContent)

    FetchContent_Declare(
        googletest
        URL https://github.com/google/googletest/archive/release-1.11.0.zip
)
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

enable_testing()

include_directories(${CMAKE_SOURCE_DIR}/include)

set(TEST_SOURCES
        JsonHandlerTest.cpp
        InvertedIndexTest.cpp
        SearchServerTest.cpp
)

add_executable(SearchEngineTests ${TEST_SOURCES})

target_link_libraries(SearchEngineTests gtest gtest_main nlohmann_json)

include(GoogleTest)
gtest_discover_tests(SearchEngineTests)
