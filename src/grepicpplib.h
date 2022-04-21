#include <cassert>
#define assertm(exp, msg) assert(((void)msg, exp))

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