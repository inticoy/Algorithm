#include <iostream>

using namespace std;

int main(void) {
  int n, i, j;
  cin >> n;
  for (i = 0; i < n; i++) {
    for (j = 0; j < i; j++) {
      printf(" ");
    }
    for (j = n; j > i; j--) {
      printf("*");
    }
    printf("\n");
  }
  return 0;
}
