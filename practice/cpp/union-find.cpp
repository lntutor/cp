#include <iostream>
#include <string>
#include <vector>
using namespace std;

#define REP(i, a, b) \
  for (int i = (int) a; i <= (int)b; i++)

int main (int argc, char const *argv[]) {
  REP(i, 0, 10) cout << i << endl;
  return 1;
}
