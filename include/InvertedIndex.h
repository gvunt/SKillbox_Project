#pragma once

#include <unordered_map>
#include <unordered_set>
#include <string>
#include <mutex>

class InvertedIndex {
public:
    void addDocument(const std::string& document, int docId);
    const std::unordered_set<int>& getDocuments(const std::string& word) const;

private:
    std::unordered_map<std::string, std::unordered_set<int>> index;
    mutable std::mutex indexMutex;
};
