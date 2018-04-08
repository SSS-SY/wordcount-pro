#include <gtest/gtest.h>
#include "word_count.h"

TEST(Test_tmh, UnitTest) {
  // test function: word_count
  auto wm = WC::WordMap{};
  EXPECT_EQ(wm, word_count(""));
  wm = WC::WordMap{{"a", 1}, {"b", 1}, {"c", 1}};
  EXPECT_EQ(wm, word_count("a b c"));
  wm = WC::WordMap{{"a", 2}, {"b", 1}, {"c", 1}};
  EXPECT_EQ(wm, word_count("a a b c"));
  wm = WC::WordMap{{"a", 1}, {"b", 1}, {"c", 1}};
  EXPECT_EQ(wm, word_count("a, b, c"));
  wm = WC::WordMap{{"a", 2}, {"b", 1}, {"c", 1}};
  EXPECT_EQ(wm, word_count("a, a. b! c?"));
  wm = WC::WordMap{{"a", 1}, {"b", 1}, {"c", 1}};
  EXPECT_EQ(wm, word_count("a&^$*@b$&@#*()c$&@*"));
  wm = WC::WordMap{{"aaa", 2}, {"aab", 1}, {"aac", 1}};
  EXPECT_EQ(wm, word_count("aaa aab aac aaa"));
  wm = WC::WordMap{{"aaa", 2}, {"aab", 1}, {"aac", 1}};
  EXPECT_EQ(wm, word_count("aaa$@aab$@&^aac*$*aaa"));
  wm = WC::WordMap{{"a", 2}};
  EXPECT_EQ(wm, word_count("a-_-a"));
  wm = WC::WordMap{{"a", 2}};
  EXPECT_EQ(wm, word_count("a_-_-_a"));
  wm = WC::WordMap{{"let", 1}, {"s", 1}, {"go-test", 1}};
  EXPECT_EQ(wm, word_count("let's go-test"));
  wm = WC::WordMap{{"let", 1}, {"s", 1}, {"go-test", 1}};
  EXPECT_EQ(wm, word_count("let's -- go-test--"));
  wm = WC::WordMap{{"let", 1}, {"s", 1}, {"go-test", 1}};
  EXPECT_EQ(wm, word_count("let's -- go-test--$@^*$@!#"));
  wm = WC::WordMap{{"a-b-c-d-e", 1}};
  EXPECT_EQ(wm, word_count("a-b-c-d-e"));
  wm = WC::WordMap{{"a-b-c-d-e", 1}, {"a-b-c-d-f", 1}};
  EXPECT_EQ(wm, word_count("a-b-c-d-e a-b-c-d-f"));
  wm = WC::WordMap{{"a-b-c-d-e", 1}, {"a-b-c-d-f", 1}};
  EXPECT_EQ(wm, word_count("a-b-c-d-e a-b-c-d-f--"));
  wm = WC::WordMap{};
  EXPECT_EQ(wm, word_count("3.1415926"));
  wm = WC::WordMap{{"F", 1}};
  EXPECT_EQ(wm, word_count("1.1.F.1.1"));
  wm = WC::WordMap{{"a", 1}, {"b", 1}, {"c", 1}};
  EXPECT_EQ(wm, word_count("124124 122 a b12.c23"));
  wm = WC::WordMap{{"a", 1}, {"b", 1}, {"c", 2}};
  EXPECT_EQ(wm, word_count("124124 122 a b12.c2323c"));
}

int main(int argc, char *argv[]) {
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
