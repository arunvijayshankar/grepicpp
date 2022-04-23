#include <iostream>
#include <cstring>
#include <vector>
#include <string>
#include "../src/grepicpplib.h"

using namespace std;

void one_result() {
    string query = "duct";
    string contents[3] = {"Rust", "safe, fast, productive.", "Pick three."};
    string ans = "safe, fast, productive.";

    if (ans.compare(search(query, contents, 3)) != 0) {
        cout << "Test one_result failed. search did not return `safe, fast, productive.`\n";
    } else {
        cout << "Found `" << query << "` in `" << search(query, contents, 3) << "`.\n";
    }
}

int main() {
    one_result();
}