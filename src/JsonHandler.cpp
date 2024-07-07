#include "../include/JsonHandler.h"
#include <fstream>
#include <sstream>
#include <algorithm>

JsonHandler::Config JsonHandler::loadConfig(const std::string& configFile) {
    std::ifstream inFile(configFile);
    json configJson;
    inFile >> configJson;

    Config config;
    for (const auto& file : configJson["files"]) {
        config.files.push_back(file.get<std::string>());
    }
    config.maxResults = configJson["max_results"].get<int>();
    config.numThreads = configJson["num_threads"].get<int>();

    return config;
}

std::vector<std::vector<std::string>> JsonHandler::loadRequests(const std::string& requestsFile) {
    std::ifstream inFile(requestsFile);
    json requestsJson;
    inFile >> requestsJson;

    std::vector<std::vector<std::string>> requests;
    for (const auto& request : requestsJson["requests"]) {
        std::string queryStr = request.get<std::string>();
        std::istringstream iss(queryStr);
        std::vector<std::string> queryWords;
        std::string word;
        while (iss >> word) {
            std::transform(word.begin(), word.end(), word.begin(), ::tolower);
            queryWords.push_back(word);
        }
        requests.push_back(queryWords);
    }

    return requests;
}

void JsonHandler::saveResults(const std::vector<std::vector<std::string>>& results, const std::string& answersFile) {
    json resultsJson;
    for (const auto& result : results) {
        resultsJson["results"].push_back(result);
    }

    std::ofstream outFile(answersFile);
    outFile << resultsJson.dump(4);
}
