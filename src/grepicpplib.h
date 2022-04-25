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
        bool case_sensitive;

        CONFIG(int argc, char *args[]) {
            assertm((argc == 3), "Not enough arguments");
            query = args[1];
            filename = args[2];
            case_sensitive = (getenv("CASE_INSENSITIVE") == NULL) ? true : false;
        }
};

void run(CONFIG );
std::vector<std::string> search(string, std::vector<std::string>);
std::vector<std::string> search_case_insensitive(string, std::vector<std::string>);
string toLower(string);