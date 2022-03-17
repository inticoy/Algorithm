#include <cmath>
#include <iostream>

using namespace std;

// - 3자리 : 1개
// - 4자리 : 9 + 10 - 1 = 18개
//     - (1666 ~ 9666) + (6660 ~ 6669)
//     - - 6666
// - 5자리 : 90 + 90 + 100 - 9 - 10 = 261
//     - (10666 ~ 99666) + (16660 ~ 96669) + (66600 ~ 66699)
//     - - (16666 ~ 96666) - (66660 ~ 66669)

// 누적 일반식 : (n + 1) * 10 ^ n - n * 10 ^ (n-1)

int cal_accum(int n);
bool is_end(int n);

int main(void) {
  int num_movie, normal;
  int i = -1;
  int digits = 2;
  int accum = cal_accum(i);
  int answer;

  cin >> num_movie;

  while (accum < num_movie) {
    i++;
    digits++;
    accum = cal_accum(i);
  }

  int min = pow(10, digits - 1);
  int max = pow(10, digits);

  accum = cal_accum(i - 1);

  for (i = min; i < max; i++) {
    if (is_end(i)) {
      accum++;
    }
    if (accum == num_movie) {
      answer = i;
      break;
    }
  }

  cout << answer;

  return 0;
}

int cal_accum(int n) {
  int i;
  int ret = 0;
  ret += (n + 1) * pow(10, n) - n * pow(10, n - 1);
  return ret;
}

bool is_end(int n) {
  bool ret = false;
  string number = to_string(n);
  int len = number.length();
  int i;
  int count = 0;
  for (i = 0; i < len; i++) {
    if (number[i] == '6')
      count++;
    else
      count = 0;
    if (count == 3)
      ret = true;
  }
  return ret;
}
