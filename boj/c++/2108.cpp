#include <algorithm>
#include <iostream>

using namespace std;

int average(int arr[], int len);
int most(int arr[], int len);

int main(void) {
  int n, i;
  cin >> n;
  int nums[n];

  for (i = 0; i < n; i++) {
    cin >> nums[i];
  }

  sort(nums, nums + n);

  // 1. average
  cout << average(nums, n) << "\n";

  // 2. middle
  cout << nums[n / 2] << "\n";

  // 3. most frequent
  cout << most(nums, n) << "\n";

  // 4. range
  cout << nums[n - 1] - nums[0];

  return 0;
}

int average(int arr[], int len) {
  int i, int_avr;
  double avr = 0;
  double diff;
  for (i = 0; i < len; i++) {
    avr += (double)arr[i];
  }
  avr /= (double)len;
  diff = avr - (int)avr;
  int_avr = (int)avr;

  if (diff > 0.5)
    return int_avr + 1;
  else if (diff > -0.5)
    return int_avr;
  else
    return int_avr - 1;
}

int most(int arr[], int len) {
  if (len == 1)
    return arr[0];

  int i;
  int freq[len];
  int num_freq = 0;

  int max_freq = 1;
  int curr_freq = 1;
  for (i = 0; i < len - 1; i++) {
    if (arr[i] == arr[i + 1]) {
      curr_freq++;
      if (curr_freq > max_freq) {
        max_freq = curr_freq;
        freq[0] = arr[i];
        num_freq = 1;
      } else if (curr_freq == max_freq) {
        freq[num_freq] = arr[i];
        num_freq++;
      }
    } else {
      curr_freq = 1;
      if (max_freq == curr_freq) {
        freq[num_freq] = arr[i];
        num_freq++;
      }
    }
  }

  if (num_freq == 1)
    return freq[0];
  else
    return freq[1];
}
