#include <iostream>

using namespace std;

int GCD(int a, int b) {
  if (a == 0)
    return b;
  return a <= b ? GCD(b % a, a) : GCD(b, a);
}

int LCM(int a, int b) { return a * b / GCD(a, b); }

int main(void) {
  int s1, s2, m1, m2;
  int lcm, gcd, son, mom;

  cin >> s1 >> m1 >> s2 >> m2;
  lcm = LCM(m1, m2);

  mom = lcm;
  son = (lcm / m1 * s1) + (lcm / m2 * s2);
  gcd = GCD(mom, son);
  mom /= gcd;
  son /= gcd;

  cout << son << " " << mom;
}
