#include <algorithm>
#include <iostream>

using namespace std;

int main(void) {
  int n, i;
  cin >> n;

  int arr[n];
  for (i = 0; i < n; i++) {
    cin >> arr[i];
  }

  sort(arr, arr + n);

  if (n % 2 == 1) {
    cout << arr[n / 2] * arr[n / 2];
  } else {
    cout << arr[0] * arr[n - 1];
  }

  return 0;
}
