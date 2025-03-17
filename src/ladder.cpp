#include "ladder.h"
#include <iostream>
#include <cctype>

using namespace std;

void error(string word1, string word2, string msg) {
    cerr << "Error with words [" << word1 << "] and [" << word2 << "]: " << msg << endl;
}

bool edit_distance_within(const string& str1, const string& str2, int d) {
    if (max(str1.size(), str2.size()) - min(str1.size(), str2.size()) > 1) {
        return false;
    }

    if (str1.size() == str2.size()) {
        int diffCount = 0;
        for (size_t i = 0; i < str1.size(); i++) {
            if (str1[i] != str2[i]) {
                diffCount++;
                if (diffCount > d) return false;
            }
        }
        return (diffCount == 1); 
    }

    const string& sShort = (str1.size() < str2.size()) ? str1 : str2;
    const string& sLong  = (str1.size() < str2.size()) ? str2 : str1;

    size_t i = 0, j = 0;
    bool foundDiff = false;
    while (i < sShort.size() && j < sLong.size()) {
        if (sShort[i] != sLong[j]) {
            if (foundDiff) return false;
            foundDiff = true;
            j++;
        } else {
            i++;
            j++;
        }
    }
    return true;
}

bool is_adjacent(const string& word1, const string& word2) {
    return edit_distance_within(word1, word2, 1);
}

vector<string> generate_word_ladder(const string&, const string&, const set<string>&) {
    return {}; 
}
void load_words(set<string>&, const string&) {}
void print_word_ladder(const vector<string>&) {}
void verify_word_ladder() {}