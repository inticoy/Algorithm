#include <iostream>

using namespace std;

int main(void) {
  int n, k, i, count;
  count = 0;
  cin >> n >> k;
  int money[n];
  for (i = 0; i < n; i++) {
    cin >> money[i];
  }

  while (k != 0) {
    count++;
    for (i = 0; i < n; i++) {
      if (k >= money[n - i - 1]) {
        k -= money[n - i - 1];
        break;
      }
    }
  }

  cout << count;

  return 0;
}
