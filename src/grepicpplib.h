#include <cassert>
#include <cstring>
#include <string>
#include <vector>
#define assertm(exp, msg) assert(((void)msg, exp))

using namespace std;

class CONFIG {
    public:
        char *query;
        char *filename;

        CONFIG(int argc, char *args[]) {
            assertm((argc == 3), "Not enough arguments");
            query = args[1];
            filename = args[2];
        }
};

void run(CONFIG );
std::vector<std::string> search(string, std::vector<std::string>);