
#include <iostream>
#include <fstream>
#include "grepicpplib.h"


using namespace std;


void run(CONFIG nConfig) {
    ifstream file (nConfig.filename);
    if ( !file.is_open() ) {
        cout << "Error opening file `" << nConfig.filename <<"`\n";
        return;
    }

    cout << "With text:\n";
    char line;
    while (file) {
        line = file.get();
        cout << line;
    }
    cout << "\n";

    file.close();
}