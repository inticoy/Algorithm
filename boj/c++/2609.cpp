#include <iostream>

using namespace std;

int gcd(int n1, int n2);
int lcm(int n1, int n2);

int main(void) {
  int num1, num2;
  cin >> num1 >> num2;

  cout << gcd(num1, num2) << "\n" << lcm(num1, num2);
  return 0;
}

int gcd(int n1, int n2) {
  if (n1 > n2) {
    return gcd(n1 - n2, n2);
  } else if (n1 < n2) {
    return gcd(n2, n1);
  } else {
    return n1;
  }
}

int lcm(int n1, int n2) { return n1 * n2 / gcd(n1, n2); }
