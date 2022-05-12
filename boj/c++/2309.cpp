#include <algorithm>
#include <iostream>

using namespace std;

int main(void) {
  int nine[9];
  int seven[7];
  int i, j, need;
  int fake1, fake2;
  int sum = 0;

  for (i = 0; i < 9; i++) {
    cin >> nine[i];
    sum += nine[i];
  }

  need = sum - 100;

  sort(nine, nine + 9);

  for (i = 0; i < 8; i++) {
    for (j = i + 1; j < 9; j++) {
      if (nine[i] + nine[j] == need) {
        fake1 = i;
        fake2 = j;
      }
    }
  }

  for (i = 0; i < 9; i++) {
    if (i == fake1 || i == fake2)
      continue;
    cout << nine[i] << "\n";
  }
  return 0;
}
