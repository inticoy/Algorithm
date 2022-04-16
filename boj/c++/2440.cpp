#include <iostream>

using namespace std;

int main(void) {
  int n, i, j;
  cin >> n;
  for (i = 0; i < n; i++) {
    for (j = n; j > i; j--) {
      printf("*");
    }
    printf("\n");
  }
  return 0;
}
