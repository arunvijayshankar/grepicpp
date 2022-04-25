#include <iostream>
#include <cstring>
#include <vector>
#include <string>
#include "../src/grepicpplib.h"

using namespace std;

void case_sensitive() {
    string query = "duct";
    vector<string> contents;
    contents.push_back("Rust");
    contents.push_back("safe, fast, productive.");
    contents.push_back("Pick three.");
    contents.push_back("Duct tape.");
    vector<string> ans;
    ans.push_back("safe, fast, productive.");
    vector<string> results = search(query, contents);

    if (ans == results) {
        cout << "Found `" << query << "` in:\n";
        if (!results.empty()) {
            for (auto i = results.begin(); i != results.end(); ++i) {
                cout << *i << '\n';
            }
        }
    } else {
        cout << "Test case_sensitive failed. search did not return:\n";
        if (!results.empty()) {
            for (auto i = results.begin(); i != results.end(); ++i) {
                cout << *i << '\n';
            }
        }
    }
}

void case_insensitive() {
    string query = "rUsT";
    vector<string> contents;
    contents.push_back("Rust");
    contents.push_back("safe, fast, productive.");
    contents.push_back("Pick three.");
    contents.push_back("Trust me.");
    vector<string> ans;
    ans.push_back("Rust");
    ans.push_back("Trust me.");
    vector<string> results = search_case_insensitive(query, contents);

    if (ans == results) {
        cout << "Found `" << query << "` in:\n";
        if (!results.empty()) {
            for (auto i = results.begin(); i != results.end(); ++i) {
                cout << *i << '\n';
            }
        }
    } else {
        cout << "Test case_insensitive failed. search did not return:\n";
        if (!results.empty()) {
            for (auto i = results.begin(); i != results.end(); ++i) {
                cout << *i << '\n';
            }
        }
    }
}

int main() {
    case_sensitive();
    case_insensitive();
}