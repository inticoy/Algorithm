#include <iostream>
#include <limits.h>

using namespace std;

bool able(int num, bool arr[]);
int digit(int num);

int main(void) {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int n, m, i, tmp, original;
  int answer = 0;

  bool broke[10];
  for (i = 0; i < 10; i++) {
    broke[i] = false;
  }
  cin >> n >> m;
  for (i = 0; i < m; i++) {
    cin >> tmp;
    broke[tmp] = true;
  }

  if (n >= 100) {
    answer = n - 100;
  } else {
    answer = 100 - n;
  }

  for (i = 0; i < 1000000; i++) {
    if (able(i, broke)) {
      if (n > i) {
        tmp = digit(i) + n - i;
      } else {
        tmp = digit(i) + i - n;
      }

      if (tmp < answer) {
        answer = tmp;
      }
    }
  }
  cout << answer;

  return 0;
}

bool able(int num, bool arr[]) {
  if (num == 0) {
    return !arr[num];
  }
  bool ret = true;
  while (num > 0) {
    if (arr[num % 10]) {
      ret = false;
      break;
    }
    num /= 10;
  }
  return ret;
}

int digit(int num) {
  if (num == 0) {
    return 1;
  }
  int ret = 0;
  while (num > 0) {
    ret++;
    num /= 10;
  }
  return ret;
}
