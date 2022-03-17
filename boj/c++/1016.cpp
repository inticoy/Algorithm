#include <iostream>

using namespace std;

int main(void) {
  long long min, max, pow;
  int i;
  long long j;
  int count = 0;
  cin >> min >> max;

  bool is_pow[max - min + 1];
  for (i = 0; i < max - min + 1; i++) {
    is_pow[i] = true;
  }

  // prime numbers ~ 1000,000
  bool is_prime[1000001];
  is_prime[0] = false;
  is_prime[1] = false;
  for (i = 2; i <= 1000000; i++) {
    is_prime[i] = true;
  }

  int prime_nums[500001];
  int num_prime = 0;

  for (i = 2; i < 1000001; i++) {
    if (is_prime[i]) {
      for (j = 2 * i; j < 1000001; j += i) {
        is_prime[j] = false;
      }
      prime_nums[num_prime] = i;
      num_prime++;
    }
  }

  for (i = 0; (long long)prime_nums[i] * (long long)prime_nums[i] <= max &&
              i < num_prime;
       i++) {

    pow = (long long)prime_nums[i] * (long long)prime_nums[i];

    for (j = min / pow; j <= max / pow; j++) {
      if (j * pow >= min)
        is_pow[j * pow - min] = false;
    }
  }

  for (i = 0; i < max - min + 1; i++) {
    if (is_pow[i]) {
      count++;
    }
  }

  cout << count;

  return 0;
}
