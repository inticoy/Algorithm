#include <iostream>

using namespace std;

int main(void) {
  int n, i, j;
  cin >> n;

  for (i = 0; i < n; i++) {
    for (j = 0; j < (n + 1) / 2; j++) {
      cout << "* ";
    }
    cout << "\n";
    for (j = 0; j < n / 2; j++) {
      cout << " *";
    }
    cout << "\n";
  }
  return 0;
}
