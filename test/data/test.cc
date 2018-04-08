#include <cstdio>
#include <iostream>

using namespace std;

int main() {
  auto fp = fopen("t8.shakespeare.txt", "r");
  fseek(fp, 0, SEEK_END);
  int file_length = ftell(fp);
  fseek(fp, 0, SEEK_SET);

  cout << file_length << endl;

  return 0;
}
