#include <gtest/gtest.h>

#include "dijkstras.h"
#include "ladder.h"

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