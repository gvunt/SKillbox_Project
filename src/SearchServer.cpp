#include "SearchServer.h"
#include <fstream>
#include <sstream>
#include <algorithm>
#include <thread>

SearchServer::SearchServer(const JsonHandler::Config& config) : maxResults(config.maxResults), numThreads(config.numThreads) {
    std::vector<std::thread> threads;
    for (size_t i = 0; i < config.files.size(); ++i) {
        threads.emplace_back(&SearchServer::indexDocument, this, config.files[i], i);
    }
    for (auto& thread : threads) {
        thread.join();
    }
}

void SearchServer::indexDocument(const std::string& file, int docId) {
    std::ifstream inFile(file);
    std::stringstream buffer;
    buffer << inFile.rdbuf();
    index.addDocument(buffer.str(), docId);
    std::lock_guard<std::mutex> lock(searchMutex);
    documents.push_back(file);
}

std::vector<std::vector<std::string>> SearchServer::search(const std::vector<std::vector<std::string>>& requests) {
    std::vector<std::vector<std::string>> results;
    std::vector<std::thread> threads;
    std::mutex resultsMutex;

    for (const auto& request : requests) {
        threads.emplace_back([&]() {
            std::unordered_map<int, int> docCount;
            for (const auto& word : request) {
                const auto& docs = index.getDocuments(word);
                for (const auto& docId : docs) {
                    docCount[docId]++;
                }
            }

            std::vector<std::pair<int, int>> sortedResults(docCount.begin(), docCount.end());
            std::sort(sortedResults.begin(), sortedResults.end(), [](const auto& a, const auto& b) {
                return b.second < a.second;
            });

            std::vector<std::string> result;
            for (size_t i = 0; i < sortedResults.size() && i < maxResults; ++i) {
                result.push_back(documents[sortedResults[i].first]);
            }

            std::lock_guard<std::mutex> lock(resultsMutex);
            results.push_back(result);
        });
    }

    for (auto& thread : threads) {
        thread.join();
    }

    return results;
}
