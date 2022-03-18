#include <algorithm>
#include <iostream>
// sum 이 int 보다 커질 수 있음.

using namespace std;

bool compare(int i, int j) { return i > j; }

int main(void) {
  int n, m, i;
  long long sum;
  cin >> n >> m;
  int arr[n];
  for (i = 0; i < n; i++) {
    cin >> arr[i];
  }

  sort(arr, arr + n, compare);

  int start = 0;
  int end = arr[0] - 1;
  int mid = (start + end) / 2;

  while (start <= end) {
    sum = 0;
    for (i = 0; i < n; i++) {
      if (arr[i] <= mid) {
        break;
      } else {
        sum += arr[i] - mid;
      }
    }
    if (sum > m) {
      start = mid + 1;
    } else if (sum < m) {
      end = mid - 1;
    } else {
      break;
    }
    mid = (start + end) / 2;
  }

  cout << mid;

  return 0;
}
