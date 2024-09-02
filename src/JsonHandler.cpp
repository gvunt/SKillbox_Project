#include "JsonHandler.h"
#include <fstream>
#include <stdexcept>

JsonHandler::Config JsonHandler::loadConfig(const std::string& filename) {
    std::ifstream configJson(R"(C:\Users\User\CLionProjects\SKillbox_Project\json\config.json)");
    if (!configJson.is_open()) {
        throw std::runtime_error("Error opening config file: " + filename);
    }

    nlohmann::json jsonConfig;
    configJson >> jsonConfig;

    Config config;
    config.files = jsonConfig["files"].get<std::vector<std::string>>();
    config.maxResults = jsonConfig["max_results"];
    config.numThreads = jsonConfig["num_threads"];

    return config;
}

std::vector<std::vector<std::string>> JsonHandler::loadRequests(const std::string& filename) {
    std::ifstream file(filename);
    if (!file.is_open()) {
        throw std::runtime_error("Error opening requests file: " + filename);
    }

    nlohmann::json jsonRequests;
    file >> jsonRequests;

    std::vector<std::vector<std::string>> requests;
    for (const auto& request : jsonRequests["requests"]) {
        std::vector<std::string> words = request.get<std::vector<std::string>>();
        requests.push_back(words);
    }

    return requests;
}

void JsonHandler::saveResults(const std::vector<std::vector<std::string>>& results, const std::string& filename) {
    nlohmann::json jsonResults;
    jsonResults["results"] = results;

    std::ofstream file(filename);
    if (!file.is_open()) {
        throw std::runtime_error("Error opening output file: " + filename);
    }

    file << jsonResults.dump(4);
}

