
#include <iostream>
#include <fstream>
#include "grepicpplib.h"
#include <string>
#include <vector>


using namespace std;


void run(CONFIG nConfig) {
    fstream file (nConfig.filename);
    if ( !file.is_open() ) {
        cout << "Error opening file `" << nConfig.filename <<"`\n";
        return;
    }
    std::vector<std::string> contents;
    std::string line;
    while (getline(file, line)) {
        contents.push_back(line);
    }
    cout << "With text:\n";
    std::vector<std::string> results = search(nConfig.query, contents);
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