#include <gtest/gtest.h>
#include "word_count.h"

TEST(Test4, UnitTest) {
  // test function: word_sort
  auto ws = WC::WordSet{};
  EXPECT_EQ(ws, word_sort({}));
  ws = WC::WordSet{{"a", 2}};
  EXPECT_EQ(ws, word_sort({{"a", 2}}));
  ws = WC::WordSet{{"a", 3}, {"b", 2}, {"c", 1}};
  EXPECT_EQ(ws, word_sort({{"a", 3}, {"b", 2}, {"c", 1}}));
  ws = WC::WordSet{{"a", 2}, {"b", 2}, {"c", 1}};
  EXPECT_EQ(ws, word_sort({{"a", 2}, {"b", 2}, {"c", 1}}));
  ws = WC::WordSet{{"a", 1}, {"b", 1}, {"c", 1}};
  EXPECT_EQ(ws, word_sort({{"a", 1}, {"b", 1}, {"c", 1}}));
  ws = WC::WordSet{{"aa", 3}, {"bb", 2}, {"cc", 1}};
  EXPECT_EQ(ws, word_sort({{"aa", 3}, {"bb", 2}, {"cc", 1}}));
  ws = WC::WordSet{{"aa", 2}, {"bb", 2}, {"cc", 1}};
  EXPECT_EQ(ws, word_sort({{"aa", 2}, {"bb", 2}, {"cc", 1}}));
  ws = WC::WordSet{{"aa", 1}, {"bb", 1}, {"cc", 1}};
  EXPECT_EQ(ws, word_sort({{"aa", 1}, {"bb", 1}, {"cc", 1}}));
  ws = WC::WordSet{{"aaa", 3}, {"aab", 2}, {"aac", 1}};
  EXPECT_EQ(ws, word_sort({{"aaa", 3}, {"aab", 2}, {"aac", 1}}));
  ws = WC::WordSet{{"aaa", 2}, {"aab", 2}, {"aac", 1}};
  EXPECT_EQ(ws, word_sort({{"aaa", 2}, {"aab", 2}, {"aac", 1}}));
  ws = WC::WordSet{{"aaa", 1}, {"aab", 1}, {"aac", 1}};
  EXPECT_EQ(ws, word_sort({{"aaa", 1}, {"aab", 1}, {"aac", 1}}));
  ws = WC::WordSet{{"a", 1}, {"aa", 1}, {"aaa", 1}};
  EXPECT_EQ(ws, word_sort({{"a", 1}, {"aa", 1}, {"aaa", 1}}));
  ws = WC::WordSet{{"aa", 2}, {"aaa", 2}, {"a", 1}};
  EXPECT_EQ(ws, word_sort({{"aa", 2}, {"aaa", 2}, {"a", 1}}));
  ws = WC::WordSet{{"aaa", 3}, {"aa", 2}, {"a", 1}};
  EXPECT_EQ(ws, word_sort({{"aaa", 3}, {"aa", 2}, {"a", 1}}));
  ws = WC::WordSet{{"a-b", 1}, {"ab", 1}};
  EXPECT_EQ(ws, word_sort({{"a-b", 1}, {"ab", 1}}));
  ws = WC::WordSet{{"ab", 2}, {"a-b", 1}};
  EXPECT_EQ(ws, word_sort({{"ab", 2}, {"a-b", 1}}));
  ws = WC::WordSet{{"a-b-c", 1}, {"abc", 1}};
  EXPECT_EQ(ws, word_sort({{"a-b-c", 1}, {"abc", 1}}));
  ws = WC::WordSet{{"a-c", 1}, {"abc", 1}};
  EXPECT_EQ(ws, word_sort({{"a-c", 1}, {"abc", 1}}));
  ws = WC::WordSet{{"abc", 2}, {"a-c", 1}};
  EXPECT_EQ(ws, word_sort({{"abc", 2}, {"a-c", 1}}));
  ws = WC::WordSet{{"a-b", 1}, {"a-c", 1}};
  EXPECT_EQ(ws, word_sort({{"a-b", 1}, {"a-c", 1}}));
}

int main(int argc, char *argv[]) {
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
