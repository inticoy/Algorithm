#include <iostream>

using namespace std;

int main(void) {
  int n, answer;
  cin >> n;

  if (n == 1) {
    cout << 1;
  } else {
    int sub = 1;
    int i;

    for (i = 1; i < n; i *= 2) {
      sub = i;
    }
    answer = (n - sub) * 2;
    cout << answer;
  }
  return 0;
}
