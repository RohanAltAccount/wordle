#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cctype>
#include <cstdlib>
#include <ctime>
// #include "crow.h"
/* int main() {
    crow::SimpleApp app;
    CROW_ROUTE(app, "/")([](){
        return "<h1>Hello from C++!</h1>";
    });
    app.port(18080).run();
} */


const int WORD_LENGTH = 5;
const int NOT_RIGHT = 0;
const int PARTIAL_RIGHT = 1;
const int RIGHT = 2;

std::string getRandomWord()
{
    std::vector<std::string> wordBank = {
"ARRAY", "CLASS", "STACK", "QUEUE", "SCOPE", "FLOAT", "CONST", "UNION", "ALIAS", "BLOCK", "ASCII", "ERRNO", "QUERY", "IOCTL", "SCALA", "RUSTC", "SWIFT", "GOLAN", "PRINT", "INPUT", "SCANF", "ALLOC", "FREES", "OPENS", "CLOSE", "BYTES",
    "CACHE", "HEAPQ", "MMAPD", "CHMOD", "CHOWN", "MOUNT", "UMASK", "HTTPD", "HTTPS", "FETCH", "DEBUG", 
    "BUILD", "PATCH", "MERGE", "SPLIT", "TOKEN", "PARSE", "LEXER", "SYNCT", "JSONS",
    "EXECS", "FORKS", "PIPES", "EVENT", "AWAIT", "ASYNC", "YIELD", "THROW", "CATCH", "FUNCT", "ESRCH", "ELIFS", "WHILE", "FINAL", "TYPES", "MACRO", "TEMPL", "NODES", "GRAPH", "EDGES", "INDEX", "VALUE", "PARAM", "FILES", "PATHS", "ROOTS", "LOOPS", "LOGIC", "CONDS", "FLAGS", "WORDS", "CLOCK", "TIMER", "DELAY", "WRITE", "READS", "SENDS", "RECVS", "PORTS", "HOSTS", "PROTO", "CODEC", "FRAME", "DEQUE", "LISTS", "TUPLE", "DICTS", "SETS", "BOOLS", "DOUBL", "CHARS", "STRNG", "REGEX", "RIGHT", "JOINS", "MAPFN", "FILTR", "REDUZ", "SORTS", "HEAPS", "TREES", "TRIES", "DFSFN", "BFSFN", "VISIT", "TRACE", "LOGFN", "PANIC", "CRASH", "ABORT", "RETRY", "SLEEP", "WAKER", "SCHED", "THRED", "MUTEX", "RAISE", "LOCKS", "RLOCK", "ULOCK", "SEMPH", "SPAWN", "JOINR", "TASKS", "FUTUR", "PROMS"

    };
  static bool seeded = false;
    if (!seeded) {
        std::srand(static_cast<unsigned>(std::time(nullptr)));
        seeded = true;
    }

    return wordBank[std::rand() % wordBank.size()];
}

int main(int, char **) {
    std::string userInput;
    std::cout << "Enter Text";
    std::getline(std::cin, userInput);
std::transform(userInput.begin(), userInput.end(), userInput.begin(), [](unsigned char c) { return std::toupper(c); });
    std::cout << userInput << std::endl;
    int numberOfTries = 6;
    std::vector<std::string> tries(numberOfTries);

    std::string target = getRandomWord();

    
bool won = false;


for (int i = 0; i < WORD_LENGTH; i++){
    if (guess[i] == target[i]) {
        result[i] = RIGHT;
    }
}

for (int i = 0; i < WORD_LENGTH; i++){
    if (result[i] != RIGHT) {
        for (int j = 0; j < WORD_LENGTH; j++){
            if (result[j] != RIGHT && guess[i] == target[j])
                result[i] = PARTIAL_RIGHT;
            break;
                }
            }
        }
    }
    return result;
}
