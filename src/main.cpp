#include <iostream>
#include "../include/JsonHandler.h"
#include "../include/SearchServer.h"

int main() {
    JsonHandler jsonHandler;
    auto config = jsonHandler.loadConfig("config.json");

    SearchServer searchServer(config);
    auto requests = jsonHandler.loadRequests("requests.json");

    auto results = searchServer.search(requests);

    jsonHandler.saveResults(results, "answers.json");

    std::cout << "Search complete. Results saved to answers.json." << std::endl;

    return 0;
}
