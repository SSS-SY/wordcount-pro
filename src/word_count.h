#ifndef WORD_COUNT_H
#define WORD_COUNT_H

#include <cstdio>
#include <string>
#include <unordered_map>
#include <utility>
#include <vector>
#include "thread_pool.hpp"

class WC {
 public:
  typedef std::vector<std::pair<std::string, int>> WordSet;
  typedef std::unordered_map<std::string, int> WordMap;

  explicit WC(const char* filename)
      : _fp(std::fopen(filename, "r")), _pool(10) {}

  ~WC() { std::fclose(_fp); }

  WordSet simple_count();

 private:
  int file_length() {
    fseek(_fp, 0, SEEK_SET);
    fseek(_fp, 0, SEEK_END);
    int ret = ftell(_fp);
    fseek(_fp, 0, SEEK_SET);

    return ret;
  }

  std::FILE* _fp;
  ThreadPool _pool;
};

WC::WordMap word_count(std::string);
WC::WordSet word_sort(const WC::WordMap&);
void output_result(const WC::WordSet&);

#endif
