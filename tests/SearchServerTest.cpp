#include <gtest/gtest.h>
#include "SearchServer.h"

TEST(SearchServerTest, Search) {
    JsonHandler::Config config;
    config.files = {"../file1.txt", "../file2.txt", "../file3.txt"};
    config.maxResults = 10;
    config.numThreads = 4;

    SearchServer searchServer(config);
    std::vector<std::vector<std::string>> requests = {
            {"example", "search", "query", "one"},
            {"another", "example", "query"},
            {"search", "for", "something", "else"}
    };

    auto results = searchServer.search(requests);

    EXPECT_EQ(results.size(), 3);
    EXPECT_GE(results[0].size(), 1);
    EXPECT_GE(results[1].size(), 1);
    EXPECT_GE(results[2].size(), 1);
}
