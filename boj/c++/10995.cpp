#include <iostream>

using namespace std;

int main(void) {
  int n, i, j;
  cin >> n;

  for (i = 0; i < n; i++) {
    for (j = 0; j < n; j++) {
      if (i % 2 == 0)
        cout << "* ";
      else
        cout << " *";
    }
    cout << "\n";
  }
  return 0;
}
