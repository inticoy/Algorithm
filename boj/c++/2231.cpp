#include <iostream>

using namespace std;

int generate(int num);

int main(void) {
  int n, i;
  int digits = 1;
  bool have_gen = false;

  cin >> n;

  for (i = 10; i < n; i *= 10) {
    digits++;
  }

  for (i = n - 9 * digits; i < n; i++) {
    if (generate(i) == n) {
      have_gen = true;
      break;
    }
  }

  if (have_gen)
    cout << i;
  else
    cout << 0;

  return 0;
}

int generate(int num) {
  int i;
  int digits = 1;
  int ret = num;

  for (i = 10; i < num; i *= 10) {
    digits++;
  }

  for (i = 0; i < digits; i++) {
    ret += num % 10;
    num /= 10;
  }

  return ret;
}
