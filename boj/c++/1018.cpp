#include <climits>
#include <iostream>

using namespace std;

int main(void) {
  int m, n, i, j, x, y, number;
  int min = INT_MAX;
  char input;
  bool standard;

  cin >> m >> n;

  // black as 0, white as 1
  bool arr[m][n];
  for (i = 0; i < m; i++) {
    for (j = 0; j < n; j++) {
      cin >> input;
      if (input == 'B')
        arr[i][j] = 0;
      else
        arr[i][j] = 1;
    }
  }

  for (x = 0; x <= m - 8; x++) {
    for (y = 0; y <= n - 8; y++) {
      standard = arr[x][y];
      number = 0;

      for (i = x; i < x + 8; i++) {
        for (j = y; j < y + 8; j++) {
          if (arr[i][j] == standard)
            number++;
          standard = !standard;
        }
        standard = !standard;
      }

      if (number > 32)
        number = 64 - number;
      if (number < min)
        min = number;
    }
  }

  cout << min;
  return 0;
}
