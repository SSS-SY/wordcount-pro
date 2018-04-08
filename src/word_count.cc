#include "word_count.h"
#include <algorithm>
#include <cctype>
#include <cstdio>
#include <fstream>
#include <regex>
#include <string>
#include <unordered_map>

using namespace std;

WC::WordSet WC::simple_count() {
  int size = file_length();
  char* buff = new (nothrow) char[size + 1];
  if (!buff) {
    return {};
  }

  fread(buff, 1, size, _fp);
  WordMap wm = word_count(string(buff));

  return word_sort(wm);
}

WC::WordSet WC::parallel_count() {
  const int block_length = 81920;
  int size = file_length();

  vector<future<WordMap>> future_results;
  for (int i = 0; i < size / block_length + 1; i++) {
    char* buff = new (nothrow) char[block_length + 1024];
    if (!buff) {
      return {};
    }

    if (fread(buff, 1, block_length, _fp) == block_length) {
      char* bp = buff + block_length;
      for (char c = fgetc(_fp); c && !isspace(c); c = fgetc(_fp), bp++) {
        *bp = c;
      }
      *bp = '\0';
    }

    future_results.push_back(_pool.enqueue(word_count, string(buff)));
    delete[] buff;
  }
  // merge all results
  WordMap result;
  for (auto& fr : future_results) {
    WordMap smap = std::move(fr.get());
    for (auto& p : smap) {
      result[p.first] += p.second;
    }
  }

  return word_sort(result);
}

WC::WordMap word_count(string buff) {
  WC::WordMap smap;
  regex rgx("[A-Za-z]+([A-Za-z-]?[A-Za-z]+)*");
  sregex_token_iterator iter(buff.begin(), buff.end(), rgx);
  sregex_token_iterator end;
  for (; iter != end; ++iter) smap[*iter]++;

  return smap;
}

WC::WordSet word_sort(const WC::WordMap& wm) {
  WC::WordSet ret;
  copy(wm.begin(), wm.end(), back_inserter(ret));
  sort(ret.begin(), ret.end(), [](pair<string, int>& x, pair<string, int>& y) {
    return x.second > y.second || (!(y.second > x.second) && x.first < y.first);
  });

  return ret;
}

void output_result(const WC::WordSet& ws) {
  ofstream fout("result.txt");
  for (int i = 0; i < ws.size() && i < 100; i++) {
    fout << (ws[i]).first << '\t' << (ws[i]).second << endl;
  }
}
