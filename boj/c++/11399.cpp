#include <iostream>

using namespace std;

void sort_arr(int *arr, int len);
int atm(int *arr, int len);

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int n;
  int i;
  int *arr;

  cin >> n;
  i = 0;
  arr = new int[n];
  while (i < n) {
    cin >> arr[i];
    i++;
  }

  sort_arr(arr, n);
  cout << atm(arr, n) << "\n";
  delete[] arr;

  return (0);
}

void sort_arr(int *arr, int len) {
  int i;
  int j;
  int temp;

  i = 0;
  while (i < len - 1) {
    j = 0;
    while (j < len - 1 - i) {
      if (arr[j] > arr[j + 1]) {
        temp = arr[j];
        arr[j] = arr[j + 1];
        arr[j + 1] = temp;
      }
      j++;
    }
    i++;
  }
}

int atm(int *arr, int len) {
  int ret;
  int i;

  ret = 0;
  i = 0;
  while (i < len) {
    ret += arr[i] * (len - i);
    i++;
  }
  return (ret);
}
