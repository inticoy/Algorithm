#include <iostream>

using namespace std;

int main(void) {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int n, i, j, number;

  cin >> n;

  int arr[10001];

  for (i = 0; i < 10001; i++) {
    arr[i] = 0;
  }

  for (i = 0; i < n; i++) {
    // scanf("%d\n", &number);
    cin >> number;
    arr[number]++;
  }

  for (i = 1; i < 10001; i++) {
    if (arr[i] > 0) {
      for (j = 0; j < arr[i]; j++) {
        cout << i << "\n";
      }
    }
  }

  return 0;
}
