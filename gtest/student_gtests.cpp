#include <gtest/gtest.h>

#include "dijkstras.h"
#include "ladder.h"

using namespace std;

TEST(Adjacent, SameLength) {
    EXPECT_TRUE(is_adjacent("cat","cot"));
    EXPECT_TRUE(is_adjacent("code","cade"));
    EXPECT_FALSE(is_adjacent("cat","dog"));
    EXPECT_FALSE(is_adjacent("cat","cat"));
}

TEST(Adjacent, DiffLength) {
    EXPECT_TRUE(is_adjacent("cat","at")); 
    EXPECT_TRUE(is_adjacent("cat","chat"));
    EXPECT_TRUE(is_adjacent("cat","cats"));
}

TEST(Adjacent, InsertDelete) {
    EXPECT_TRUE(is_adjacent("cat","at"));
    EXPECT_TRUE(is_adjacent("chat","hat"));
    EXPECT_TRUE(is_adjacent("cat","scat"));
    EXPECT_TRUE(is_adjacent("data","date"));
    EXPECT_FALSE(is_adjacent("cat","catsy"));
    EXPECT_FALSE(is_adjacent("cat","act"));
}

TEST(BFS, TestGenerateWordLadder) {
    set<string> dict = {"cat","cot","cog","dog","fog"};
    auto ladder = generate_word_ladder("cat","dog", dict);
    ASSERT_EQ(ladder.size(), 4u);
    EXPECT_EQ(ladder[0], "cat");
    EXPECT_EQ(ladder[1], "cot");
    EXPECT_EQ(ladder[2], "cog");
    EXPECT_EQ(ladder[3], "dog");
}
