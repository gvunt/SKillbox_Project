#pragma once

#include "JsonHandler.h"
#include "InvertedIndex.h"
#include <vector>
#include <string>
#include <unordered_map>
#include <mutex>

class SearchServer {
public:
    SearchServer(const JsonHandler::Config& config);
    std::vector<std::vector<std::string>> search(const std::vector<std::vector<std::string>>& requests);

private:
    void indexDocument(const std::string& file, int docId);
    std::vector<std::string> documents;
    InvertedIndex index;
    int maxResults;
    int numThreads;
    std::mutex searchMutex;
};
