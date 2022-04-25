#include <iostream>
#include <string>
#include "grepicpplib.h"

using namespace std;


int main(int argc, // argument count
        char *argv[], // pointer to an array of strings of passed arguments
        char *envp[] // pointer to an array of strings of env variables
        )
{

    CONFIG nConfig(argc, argv);
    cout << "Searching for `" << nConfig.query << "`\n";
    cout << "In file `" << nConfig.filename << "`\n";

    run(nConfig);
}
