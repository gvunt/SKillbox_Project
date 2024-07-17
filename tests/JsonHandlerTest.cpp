#include <gtest/gtest.h>
#include "JsonHandler.h"

TEST(JsonHandlerTest, LoadConfig) {
    JsonHandler jsonHandler;
    JsonHandler::Config config = jsonHandler.loadConfig("../config.json");

    EXPECT_EQ(config.files.size(), 3);
    EXPECT_EQ(config.maxResults, 10);
    EXPECT_EQ(config.numThreads, 4);
}

TEST(JsonHandlerTest, LoadRequests) {
    JsonHandler jsonHandler;
    auto requests = jsonHandler.loadRequests("../requests.json");

    EXPECT_EQ(requests.size(), 3);
    EXPECT_EQ(requests[0].size(), 4);
    EXPECT_EQ(requests[1].size(), 3);
    EXPECT_EQ(requests[2].size(), 4);
}

TEST(JsonHandlerTest, SaveResults) {
    JsonHandler jsonHandler;
    std::vector<std::vector<std::string>> results = {
            {"file1.txt", "file2.txt"},
            {"file2.txt", "file1.txt"},
            {"file3.txt"}
    };
    jsonHandler.saveResults(results, "test_answers.json");

    std::ifstream inFile("test_answers.json");
    nlohmann::json answersJson;
    inFile >> answersJson;

    EXPECT_EQ(answersJson["results"].size(), 3);
    EXPECT_EQ(answersJson["results"][0].size(), 2);
    EXPECT_EQ(answersJson["results"][1].size(), 2);
    EXPECT_EQ(answersJson["results"][2].size(), 1);
}
