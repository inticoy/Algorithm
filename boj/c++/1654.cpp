#include <iostream>
#include <algorithm>

// answer : min of lengths ~ max of lengths

using namespace std;

int cal_n(unsigned int arr[], int len, unsigned int length);

int main(void){
  int k, n, i;
  unsigned int start, mid, end, n_mid;

  cin >> k >> n;
  unsigned int lengths[k];

  for(i = 0; i < k; i++){
    cin >> lengths[i];
  }
  sort(lengths, lengths + k);

  start = 1;
  end = lengths[k - 1];
  mid = (start + end) / 2;

  while(start <= end){
    n_mid = cal_n(lengths, k, mid);
    if (n_mid >= n) {
      start = mid + 1;
    } else {
      end = mid - 1;
    }
    mid = (start + end) / 2;
  }

  cout << mid;

  return 0;
}

int cal_n(unsigned int arr[], int len, unsigned int length){
  int num = 0;
  for (int i = 0; i < len; i++){
    num += arr[i] / length;
  }
  return num;
}
