#include "word_count.h"

int main(int argc, char* argv[]) {
  WC wc(argv[1]);
  auto ws = wc.simple_count();
  output_result(ws);

  return 0;
}