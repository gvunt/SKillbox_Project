#include "InvertedIndex.h"
#include <sstream>
#include <algorithm>

void InvertedIndex::addDocument(const std::string& document, int docId) {
    std::istringstream iss(document);
    std::string word;
    std::lock_guard<std::mutex> lock(indexMutex);
    while (iss >> word) {
        std::transform(word.begin(), word.end(), word.begin(), ::tolower);
        index[word].insert(docId);
    }
}

const std::unordered_set<int>& InvertedIndex::getDocuments(const std::string& word) const {
    static std::unordered_set<int> emptySet;
    std::lock_guard<std::mutex> lock(indexMutex);
    auto it = index.find(word);
    return (it != index.end()) ? it->second : emptySet;
}
