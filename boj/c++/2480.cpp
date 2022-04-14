#include <iostream>

using namespace std;

int main(void) {
  int a, b, c;
  int same = 0;
  int same_num = -1;

  cin >> a >> b >> c;

  if (a == b) {
    same++;
    same_num = a;
  }
  if (b == c) {
    same++;
    same_num = b;
  }
  if (c == a) {
    same++;
    same_num = c;
  }

  if (same == 3) {
    cout << 10000 + 1000 * a;
  } else if (same == 1) {
    cout << 1000 + 100 * same_num;
  } else {
    int biggest;
    if (a > b && a > c)
      biggest = a;
    if (b > c && b > a)
      biggest = b;
    if (c > a && c > b)
      biggest = c;
    cout << 100 * biggest;
  }

  return 0;
}
