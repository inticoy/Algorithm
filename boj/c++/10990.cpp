#include <iostream>

using namespace std;

int main(void) {
  int n, i, j;
  cin >> n;

  for (i = 0; i < n; i++) {
    for (j = 0; j < n - i - 1; j++) {
      cout << " ";
    }
    cout << "*";

    if (i != 0) {
      for (j = 0; j < 2 * i - 1; j++) {
        cout << " ";
      }
      cout << "*";
    }
    cout << "\n";
  }
  return 0;
}
