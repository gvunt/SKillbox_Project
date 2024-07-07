#pragma once

#include <string>
#include <vector>
#include "nlohmann/json.hpp"

using json = nlohmann::json;

class JsonHandler {
public:
    struct Config {
        std::vector<std::string> files;
        int maxResults;
        int numThreads;
    };

    Config loadConfig(const std::string& configFile);
    std::vector<std::vector<std::string>> loadRequests(const std::string& requestsFile);
    void saveResults(const std::vector<std::vector<std::string>>& results, const std::string& answersFile);
};
