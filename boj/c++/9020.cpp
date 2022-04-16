#include <iostream>

using namespace std;

int main(void) {
  int n = 10000;
  int i, j, times, num, left, right;

  bool is_prime[n + 1];

  is_prime[0] = false;
  is_prime[1] = false;

  for (i = 2; i < n + 1; i++) {
    is_prime[i] = true;
  }

  for (i = 2; i <= n; i++) {
    if (is_prime[i]) {
      for (j = 2 * i; j <= n; j += i) {
        is_prime[j] = false;
      }
    }
  }

  cin >> times;

  for (i = 0; i < times; i++) {
    cin >> num;
    left = num / 2;
    while (true) {
      right = num - left;
      if (is_prime[left] && is_prime[right]) {
        break;
      } else {
        left--;
      }
    }
    cout << left << " " << right << "\n";
  }
  return 0;
}
