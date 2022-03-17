#include <algorithm>
#include <iostream>

using namespace std;

int main(void) {
  int n, i, j, max;
  int answer = 0;

  cin >> n;
  int numbers[n];
  for (i = 0; i < n; i++) {
    cin >> numbers[i];
  }
  sort(numbers, numbers + n);
  max = numbers[n - 1];

  bool is_prime[max + 1];
  int prime_nums[max / 2 + 1];
  int num_prime_nums = 0;

  is_prime[0] = false;
  is_prime[1] = false;

  for (i = 2; i < max + 1; i++) {
    is_prime[i] = true;
  }

  for (i = 2; i <= max; i++) {
    if (is_prime[i]) {
      prime_nums[num_prime_nums] = i;
      num_prime_nums++;
      for (j = 2 * i; j <= max; j += i) {
        is_prime[j] = false;
      }
    }
  }

  for (i = 0; i < n; i++) {
    if (is_prime[numbers[i]]) {
      answer++;
    }
  }

  cout << answer;

  return 0;
}
