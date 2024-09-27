// hello.cpp
#include <iostream>
#include <ctime>

using namespace std;

int main() {
  clock_t before = clock();
  int k = 0;
  for (int i = 0; i < 100000; i++) {
    k += i;
  }
  clock_t duration = clock() - before;
  cout << "Duration: " << (float)duration / CLOCKS_PER_SEC << " seconds";
  return 0;
}