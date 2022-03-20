#include <iostream>

using namespace std;

int GCD_remain(int a, int b);
int GCD_sub(int a, int b);
int main(void) {
  int a = 5;
  int b = 5;
  cout << GCD_sub(a, b) << endl;
  return 0;
}

// a == b case must be checked
int GCD_remain(int a, int b) {
  if (a)
    return (a > b) ? GCD_remain(a % b, b) : GCD_remain(b, a);
  else
    return b;
}

int GCD_sub(int a, int b) {
  if (a == b)
    return a;
  else
    return a > b ? GCD_sub(a - b, b) : GCD_sub(b, a);
}
