#include <iostream>

using namespace std;

int main(void) {
  int n, k, i;
  int answer = 1;
  cin >> n >> k;

  for (i = 0; i < k; i++) {
    answer *= n - i;
  }

  for (i = 1; i <= k; i++) {
    answer /= i;
  }

  cout << answer;
}
