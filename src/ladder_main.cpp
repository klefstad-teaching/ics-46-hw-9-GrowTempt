#include "ladder.h"
#include <iostream>

using namespace std;

int main(int argc, char* argv[]) {
    //verify_word_ladder();

    if (argc < 3) {
        cerr << "Usage: " << argv[0] << " <start_word> <end_word>\n";
        return 1;
    }
    string start = argv[1];
    string end   = argv[2];

    for (auto &c : start) c = tolower((unsigned char)c);
    for (auto &c : end)   c = tolower((unsigned char)c);

    set<string> dictionary;
    load_words(dictionary, "../src/words.txt");

    auto ladder = generate_word_ladder(start, end, dictionary);
    print_word_ladder(ladder);

    return 0;
}
