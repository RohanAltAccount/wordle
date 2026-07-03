#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cctype>
#include <cstdlib>
#include <ctime>
#include <emscripten.h>

const int WORD_LENGTH = 5;
const int NOT_RIGHT = 0;
const int PARTIAL_RIGHT = 1;
const int RIGHT = 2;

std::string targetWord;

std::string getRandomWord() {
    std::vector<std::string> wordBank = {
        "ARRAY", "CLASS", "STACK", "QUEUE", "SCOPE", "FLOAT", "CONST", "UNION", "ALIAS", 
        "BLOCK", "ASCII", "ERRNO", "QUERY", "IOCTL", "SCALA", "RUSTC", "SWIFT", "GOLAN", 
        "PRINT", "INPUT", "SCANF", "ALLOC", "FREES", "OPENS", "CLOSE", "BYTES", "CACHE", 
        "HEAPQ", "MMAPD", "CHMOD", "CHOWN", "MOUNT", "UMASK", "HTTPD", "HTTPS", "FETCH", 
        "DEBUG", "BUILD", "PATCH", "MERGE", "SPLIT", "TOKEN", "PARSE", "LEXER", "SYNCT", 
        "JSONS", "EXECS", "FORKS", "PIPES", "EVENT", "AWAIT", "ASYNC", "YIELD", "THROW", 
        "CATCH", "FUNCT", "ESRCH", "ELIFS", "WHILE", "FINAL", "TYPES", "MACRO", "TEMPL", 
        "NODES", "GRAPH", "EDGES", "INDEX", "VALUE", "PARAM", "FILES", "PATHS", "ROOTS", 
        "LOOPS", "LOGIC", "CONDS", "FLAGS", "WORDS", "CLOCK", "TIMER", "DELAY", "WRITE", 
        "READS", "SENDS", "RECVS", "PORTS", "HOSTS", "PROTO", "CODEC", "FRAME", "DEQUE", 
        "LISTS", "TUPLE", "DICTS", "SETS", "BOOLS", "DOUBL", "CHARS", "STRNG", "REGEX", 
        "RIGHT", "JOINS", "MAPFN", "FILTR", "REDUZ", "SORTS", "HEAPS", "TREES", "TRIES", 
        "DFSFN", "BFSFN", "VISIT", "TRACE", "LOGFN", "PANIC", "CRASH", "ABORT", "RETRY", 
        "SLEEP", "WAKER", "SCHED", "THRED", "MUTEX", "RAISE", "LOCKS", "RLOCK", "ULOCK", 
        "SEMPH", "SPAWN", "JOINR", "TASKS", "FUTUR", "PROMS"
    };
    
    static bool seeded = false;
    if (!seeded) {
        std::srand(static_cast<unsigned>(std::time(nullptr)));
        seeded = true;
    }
    return wordBank[std::rand() % wordBank.size()];
}

extern "C" {
    EMSCRIPTEN_KEEPALIVE
    void init_game() {
        targetWord = getRandomWord();
        std::cout << "Target word initialized." << std::endl; 
    }
    EMSCRIPTEN_KEEPALIVE
    void check_guess(const char* guess_str, int* result_array) {
        std::string guess(guess_str);
        std::transform(guess.begin(), guess.end(), guess.begin(), [](unsigned char c) { 
            return std::toupper(c); 
        });

        std::vector<int> result(WORD_LENGTH, NOT_RIGHT);
        std::vector<bool> targetUsed(WORD_LENGTH, false);
        std::vector<bool> guessUsed(WORD_LENGTH, false);

        for (int i = 0; i < WORD_LENGTH; i++) {
            if (guess[i] == targetWord[i]) {
                result[i] = RIGHT;
                targetUsed[i] = true;
                guessUsed[i] = true;
            }
        }

        for (int i = 0; i < WORD_LENGTH; i++) {
            if (guessUsed[i]) continue;
            
            for (int j = 0; j < WORD_LENGTH; j++) {
                if (!targetUsed[j] && guess[i] == targetWord[j]) {
                    result[i] = PARTIAL_RIGHT;
                    targetUsed[j] = true;
                    break;
                }
            }
        }

        for (int i = 0; i < WORD_LENGTH; i++) {
            result_array[i] = result[i];
        }
    }
}

int main() {
    init_game();
    return 0;
}
