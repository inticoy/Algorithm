#include <iostream>

using namespace std;

int GCD(int a, int b);
int main(void) {
  int a = 468;
  int b = 9120;
  cout << GCD(a, b) << endl;
  return 0;
}

int GCD(int a, int b) {
  if (a == 0)
    return b;
  return a <= b ? GCD(b % a, a) : GCD(b, a);
}
