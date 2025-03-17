#include <gtest/gtest.h>

#include "dijkstras.h"
#include "ladder.h"

TEST(Step1, AdjacentSameLength) {
    EXPECT_TRUE(is_adjacent("cat","cot"));
    EXPECT_TRUE(is_adjacent("code","cade"));
    EXPECT_FALSE(is_adjacent("cat","dog"));
    EXPECT_FALSE(is_adjacent("cat","cat"));
}

TEST(Step1, AdjacentDiffLength) {
    EXPECT_FALSE(is_adjacent("cat","at")); 
    EXPECT_FALSE(is_adjacent("cat","chat"));
    EXPECT_FALSE(is_adjacent("cat","cats"));
}