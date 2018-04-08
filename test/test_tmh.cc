#include <gtest/gtest.h>
#include "word_count.h"

TEST(Test2, UnitTest) {
  // test function: simple_count
  auto wc = new WC("data/nonexist.txt");
  EXPECT_TRUE(WC:WordSet{} == wc.simple_count());
  delete wc;
  wc = new WC("data/pg-grimm.txt");
  EXPECT_TRUE(WC:WordSet{} != wc.simple_count());
  delete wc;
  wc = new WC("data/t8.shakespeare.txt")
  EXPECT_TRUE(WC:WordSet{} != wc.simple_count());
  delete wc;
  // test function: word_count
  auto wm = WC::WordMap{{"the", 3}};
  EXPECT_EQ(wm, word_count("the the the"));
  wm = WC::WordMap{{"hello", 2}};
  EXPECT_EQ(wm, word_count("hello, hello"));
  wm = WC::WordMap{{"Hey", 1}, {"hey", 1}};
  EXPECT_EQ(wm, word_count("Hey! hey"));
  wm = WC::WordMap{{"let", 1}, {"s", 1}, {"go", 1}};
  EXPECT_EQ(wm, word_count("let's go!'"));
  wm = WC::WordMap{{"qq", 1}, {"com", 1}};
  EXPECT_EQ(wm, word_count("123456@qq.com"));
  wm = WC::WordMap{};
  EXPECT_EQ(wm, word_count("15207104560"));
  wm = WC::WordMap{};
  EXPECT_EQ(wm, word_count("124.11&&!"));
  wm = WC::WordMap{{"wow-wow-wow", 1}};
  EXPECT_EQ(wm, word_count("wow-wow-wow"));
  wm = WC::WordMap{{"yaourt", 1}, {"Syua", 1}};
  EXPECT_EQ(wm, word_count("yaourt --Syua"));
  wm = WC::WordMap{{"ahahahahah", "1"}};
  EXPECT_EQ(wm, word_count("ahahahahah----"));
  // test function: word_sort
  auto ws = WC::WordSet{{"the": 100}};
  EXPECT_EQ(ws, word_sort({{"the": 100}}));
  ws = WC::WordSet{{"so", 100}, {"amazing", 10}};
  EXPECT_EQ(ws, word_sort({{"so", 100}, {"amazing", 10}}));
  ws = WC::WordSet{{"do", 100}, {"you", 99}, {"remember": 98}, {"me": 97}};
  EXPECT_EQ(ws, word_sort({{"do", 100}, {"you", 99}, {"remember": 98}, {"me": 97}}));
  ws = WC::WordSet{{"so", 100}, {"soul", 100}, {"amazing", 10}};
  EXPECT_EQ(ws, word_sort({{"so", 100}, {"soul", 100}, {"amazing", 10}}));
  ws = WC::WordSet{{"The", 2}, {"the", 2}};
  EXPECT_EQ(ws, word_sort({{"The": 2}, {"the": 2}}));
  ws = WC::WordSet{{"the", 3}, {"The", 2}};
  EXPECT_EQ(ws, word_sort({{"the", 3}, {"The", 2}}));
  ws = WC::WordSet{{"leet-code", 1}, {"leetcode", 1}};
  EXPECT_EQ(ws, word_sort({{"leet-code", 1}, {"leetcode", 1}}));
  ws = WC::WordSet{{"leetcode", 2}, {"leet-code", 1}};
  EXPECT_EQ(ws, word_sort({{"leetcode", 2}, {"leet-code", 1}}));
}

int main(int argc, char *argv[]) {
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
