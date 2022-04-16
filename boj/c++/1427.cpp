#include <iostream>

using namespace std;

int main(void) {
  string n;
  int i, j, len;
  int numbers[10];
  for (i = 0; i < 10; i++) {
    numbers[i] = 0;
  }

  cin >> n;
  len = n.length();

  for (i = 0; i < len; i++) {
    numbers[n[i] - '0']++;
  }

  for (i = 9; i >= 0; i--) {
    for (j = 0; j < numbers[i]; j++) {
      cout << i;
    }
  }
  return 0;
}
