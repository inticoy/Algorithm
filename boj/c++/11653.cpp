#include <iostream>

using namespace std;

int main(void) {
  int n, i, j;

  cin >> n;
  bool is_prime[n + 1];
  int prime_nums[n / 2 + 1];
  int num_prime_nums = 0;

  is_prime[0] = false;
  is_prime[1] = false;

  for (i = 2; i < n + 1; i++) {
    is_prime[i] = true;
  }

  for (i = 2; i <= n; i++) {
    if (is_prime[i]) {
      prime_nums[num_prime_nums] = i;
      num_prime_nums++;
      for (j = 2 * i; j <= n; j += i) {
        is_prime[j] = false;
      }
    }
  }

  for (i = 0; i <= n; i++) {
    if (is_prime[i]) {
      while (n % i == 0) {
        n /= i;
        cout << i << "\n";
      }
    }
  }

  return 0;
}
