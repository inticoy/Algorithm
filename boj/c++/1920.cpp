#include <algorithm>
#include <iostream>

using namespace std;

bool find_num(int arr[], int len, int num);

int main(void) {
  int n, m, i;
  bool exist;

  cin >> n;
  int n_arr[n];
  for (i = 0; i < n; i++) {
    cin >> n_arr[i];
  }

  sort(n_arr, n_arr + n);

  cin >> m;
  int m_arr[m];
  for (i = 0; i < m; i++) {
    cin >> m_arr[i];
  }

  for (i = 0; i < m; i++) {
    exist = find_num(n_arr, n, m_arr[i]);
    if (exist) {
      cout << '1' << '\n';
    } else {
      cout << '0' << '\n';
    }
  }

  return 0;
}

bool find_num(int arr[], int len, int num) {
  int start = 0;
  int end = len - 1;
  int mid = (start + end) / 2;

  while (start <= end) {
    if (arr[mid] > num) {
      end = mid - 1;
    } else if (arr[mid] < num) {
      start = mid + 1;
    } else {
      return true;
    }
    mid = (start + end) / 2;
  }
  return false;
}
