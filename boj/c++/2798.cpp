#include <iostream>

using namespace std;

int main(void) {
  int n, m, i, j, k, sum;
  int max = 0;
  cin >> n >> m;
  int arr[n];
  for (i = 0; i < n; i++) {
    cin >> arr[i];
  }

  for (i = 0; i <= n - 3; i++) {
    for (j = i + 1; j <= n - 2; j++) {
      for (k = j + 1; k <= n - 1; k++) {
        sum = arr[i] + arr[j] + arr[k];
        if (sum > max && sum <= m) {
          max = sum;
        }
      }
    }
  }

  cout << max;
  return 0;
}
