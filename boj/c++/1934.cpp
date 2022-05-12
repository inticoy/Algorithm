#include <iostream>

using namespace std;

int GCD(int a, int b) {
  if (a == 0)
    return b;
  return a <= b ? GCD(b % a, a) : GCD(b, a);
}

int LCM(int a, int b) { return a * b / GCD(a, b); }

int main(void) {
  int n, i;
  int a, b;
  cin >> n;

  for (i = 0; i < n; i++) {
    cin >> a >> b;
    cout << LCM(a, b) << "\n";
  }
}
