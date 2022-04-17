#include <iostream>

using namespace std;

int main(void) {
  int n, i, j;
  cin >> n;
  string first("");
  string center("");

  for (i = 0; i < n; i++) {
    first += "*";
  }
  for (i = 0; i < 2 * n - 3; i++) {
    first += " ";
  }
  for (i = 0; i < n; i++) {
    first += "*";
  }

  for (i = 0; i < n - 1; i++) {
    center += " ";
  }

  center += "*";

  for (i = 0; i < n - 2; i++) {
    center += " ";
  }

  center += "*";

  for (i = 0; i < n - 2; i++) {
    center += " ";
  }

  center += "*";

  cout << first << "\n";

  for (i = 0; i < n - 2; i++) {
    for (j = 0; j < i + 1; j++) {
      cout << " ";
    }

    cout << "*";

    for (j = 0; j < n - 2; j++) {
      cout << " ";
    }

    cout << "*";

    for (j = 0; j < 2 * (n - 2 - i) - 1; j++) {
      cout << " ";
    }

    cout << "*";

    for (j = 0; j < n - 2; j++) {
      cout << " ";
    }

    cout << "*\n";
  }

  cout << center << "\n";

  for (i = n - 3; i >= 0; i--) {
    for (j = 0; j < i + 1; j++) {
      cout << " ";
    }

    cout << "*";

    for (j = 0; j < n - 2; j++) {
      cout << " ";
    }

    cout << "*";

    for (j = 0; j < 2 * (n - 2 - i) - 1; j++) {
      cout << " ";
    }

    cout << "*";

    for (j = 0; j < n - 2; j++) {
      cout << " ";
    }

    cout << "*\n";
  }

  cout << first << "\n";

  return 0;
}
