#include <iostream>

using namespace std;

int main(void) {
  int n, i, j, x;
  cin >> n;
  for (i = 0; i < 2 * n - 1; i++) {
    x = i;
    if (i >= n)
      x = 2 * n - 2 - i;
    for (j = 0; j < x + 1; j++) {
      printf("*");
    }
    for (j = 0; j < 2 * (n - x - 1); j++) {
      printf(" ");
    }
    for (j = 0; j < x + 1; j++) {
      printf("*");
    }
    printf("\n");
  }

  return 0;
}
