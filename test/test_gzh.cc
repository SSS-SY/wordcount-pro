#include <gtest/gtest.h>
#include "word_count.h"

TEST(Test3, UnitTest) {
  // test function: file_length
  auto wc = new WC("data/error.txt");
  EXPECT_EQ(0, wc.file_length());
  delete wc;
  wc = new WC("data/pg-grimm.txt");
  EXPECT_EQ(540174, wc.file_length());
  delete wc;
  wc = new WC("data/t8.shakespeare.txt");
  EXPECT_EQ(5458199, wc.file_length());
  delete wc;
  // test function: word_count
  auto wm = WC::WordMap{{"qAp": 1}};
  EXPECT_EQ(wm, word_count("qAp"));
  wm = WC::WordMap{{"Google", 1}, {"Cloud", 1}, {"Platform", 1}};
  EXPECT_EQ(wm, word_count("Google Cloud Platform"));
  wm = WC::WordMap{{"Google", 2}, {"Cloud", 2}, {"Platform", 2}};
  EXPECT_EQ(wm, word_count("Google Cloud Platform/Google Cloud Platform"));
  wm = WC::WordMap{{"CloudPlatform-noreply", 1}, {"google", 1}, {"com", 1}};
  EXPECT_EQ(wm, word_count("CloudPlatform-noreply@google.com"));
  wm = WC::WordMap{{"https", 1}, {"ctrip", 1}, {"acmcoder", 1}, {"com": 1}, {"cand": 1}, {"login": 1}};
  EXPECT_EQ(wm, word_count("https://ctrip.acmcoder.com/cand/login"));
  wm = WC::WordMap{};
  EXPECT_EQ(wm, word_count("2018-03-29 20:30"));
  wm = WC::WordMap{{"April": 1}, {"AM": 1}, {"PT": 1}};
  EXPECT_EQ(wm, word_count("April 3, 9 AM PT"));
  wm = WC::WordMap{{"test": 1}};
  EXPECT_EQ(wm, word_count("--test--"));
  wm = WC::WordMap{{"test-test", 1}};
  EXPECT_EQ(wm, word_count("--test-test--"));
  wm = WC::WordMap{{"test", 2}};
  EXPECT_EQ(wm, word_count("--test--test--"));
  wm = WC::WordMap{{"test", 2}};
  EXPECT_EQ(wm, word_count("--test1-1test--"));
  // test function: word_sort
  auto ws = WC::WordSet{{"Google", 1}};
  EXPECT_EQ(ws, word_sort({{"Google", 1}}));
  ws = WC::WordSet{{"Google", 1}, {"google", 1}};
  EXPECT_EQ(ws, word_sort({{"Google", 1}, {"google", 1}}));
  ws = WC::WordSet{{"googlE", 1}, {"google", 1}};
  EXPECT_EQ(ws, word_sort({{"googlE", 1}, {"google", 1}}));
  ws = WC::WordSet{{"what", 7}, {"the", 6}, {"xx", 1}};
  EXPECT_EQ(ws, word_sort({{"what", 7}, {"the", 6}, {"xx", 1}}));
  ws = WC::WordSet{{"g--gle", 1}, {"google", 1}};
  EXPECT_EQ(ws, word_sort({{"g--gle", 1}, {"google", 1}}));
  ws = WC::WordSet{{"http", 1}, {"https", 1}};
  EXPECT_EQ(ws, word_sort({{"http", 1}, {"https", 1}}));
}

int main(int argc, char *argv[]) {
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
