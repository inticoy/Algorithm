#include <iostream>

using namespace std;

int cal(int floor, int num);

int main(void) {
  int T, k, n, i; // variables for problem
  cin >> T;

  for (i = 0; i < T; i++) {
    cin >> k;
    cin >> n;

    cout << cal(k, n) << "\n";
  }

  return 0;
}

int cal(int floor, int num) {
  if (floor == 0) {
    return num;
  } else {
    int i;
    int ret = 0;
    for (i = 1; i <= num; i++) {
      ret += cal(floor - 1, i);
    }
    return ret;
  }
  return 0;
}
