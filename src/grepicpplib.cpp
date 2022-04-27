
#include <iostream>
#include <fstream>
#include "grepicpplib.h"
#include <string>
#include <vector>
#include <cctype>
#include <algorithm>


using namespace std;

string toLower(string data) {
    std::transform(data.begin(), data.end(), data.begin(),
        [](unsigned char c){return tolower(c); });
    return data;
}

void run(CONFIG nConfig) {
    fstream file (nConfig.filename);
    if ( !file.is_open() ) {
        cerr << "Error opening file `" << nConfig.filename <<"`\n";
        return;
    }
    std::vector<std::string> contents;
    std::string line;
    while (getline(file, line)) {
        contents.push_back(line);
    }
    cout << "With text:\n";
    std::vector<std::string> results;
    if (nConfig.case_sensitive) {
        results = search(nConfig.query, contents);
    } else {
        results = search_case_insensitive(nConfig.query, contents);
    }
    if (!results.empty()) {
        for (auto i = results.begin(); i != results.end(); ++i) {
            cout << *i << '\n';
        }
    }
    cout << "\n";

    file.close();
}

std::vector<std::string> search(string query, std::vector<std::string> contents) {
    std::vector<std::string> results;
    for (auto i = contents.begin(); i != contents.end(); ++i) {
        string line = *i;
        if (line.find(query) != string::npos) {
            results.push_back(line);
        }
    }
    return results;
}

std::vector<std::string> search_case_insensitive(string query, std::vector<std::string> contents) {
    std::vector<std::string> results;
    string query_lower = toLower(query);
    for (auto i = contents.begin(); i != contents.end(); ++i) {
        string line = *i;
        string line_lower = toLower(line);
        if (line_lower.find(query_lower) != string::npos) {
            results.push_back(line);
        }
    }
    return results;
}