#include <iostream>

using namespace std;

int main(void) {
  int n, i, left, answer;
  bool possible = false;
  cin >> n;

  for (i = n / 5; i >= 0; i--) {
    left = n - i * 5;
    if (left % 3 == 0) {
      answer = i + left / 3;
      possible = true;
      break;
    }
  }

  if (possible)
    cout << answer;
  else
    cout << "-1";

  return 0;
}
