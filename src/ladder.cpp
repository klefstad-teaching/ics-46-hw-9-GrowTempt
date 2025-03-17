#include "ladder.h"
#include <fstream>
#include <queue>
#include <iostream>
#include <cctype>
#include <algorithm>
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

vector<string> generate_word_ladder(const string& begin_word, const string& end_word, const set<string>& word_list) {
    if (begin_word == end_word) {
        return {};
    }

    queue<vector<string>> ladderQ;
    ladderQ.push({ begin_word });

    set<string> visited;
    visited.insert(begin_word);

    while (!ladderQ.empty()) {
        auto currentLadder = ladderQ.front();
        ladderQ.pop();

        const string& lastWord = currentLadder.back();
        for (auto & candidate : word_list) {
            if (!visited.count(candidate) && is_adjacent(lastWord, candidate)) {
                visited.insert(candidate);

                auto newLadder = currentLadder;
                newLadder.push_back(candidate);

                if (candidate == end_word) {
                    return newLadder;
                }
                ladderQ.push(newLadder);
            }
        }
    }
    return {};
}

void load_words(set<string> & word_list, const string& file_name) {
    word_list.clear();
    ifstream in(file_name);
    if (!in) {
        cerr << "Cannot open file: " << file_name << endl;
        return;
    }
    string w;
    while (in >> w) {
        for (auto &c : w) {
            c = tolower(static_cast<unsigned char>(c));
        }
        word_list.insert(w);
    }
}

void print_word_ladder(const vector<string>& ladder) {
    if (ladder.empty()) {
        return;
    }
    for (size_t i = 0; i < ladder.size(); i++) {
        cout << ladder[i];
        if (i + 1 < ladder.size()) cout << " ";
    }
    cout << endl;
}

void verify_word_ladder() {}