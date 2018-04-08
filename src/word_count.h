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
      : _fp(std::fopen(filename, "r")), _pool(10) {
    if (_fp) {
      std::fseek(_fp, 0, std::SEEK_END);
      _file_length = std::ftell(_fp);
      std::fseek(_fp, 0, std::SEEK_SET);
    }
  }

  ~WC() { std::fclose(_fp); }

  WordSet simple_count();

  int file_length() { return _file_length; }

 private:
  std::FILE* _fp;
  int _file_length;
  ThreadPool _pool;
};

WC::WordMap word_count(std::string);
WC::WordSet word_sort(const WC::WordMap&);
void output_result(const WC::WordSet&);

#endif
