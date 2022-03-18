#include <algorithm>
#include <iostream>

using namespace std;

bool is_right(int a, int b, int c);

int main(void) {
  int a, b, c;
  while (true) {
    cin >> a >> b >> c;
    if (a == 0 && b == 0 && c == 0)
      break;

    if (is_right(a, b, c)) {
      cout << "right\n";
    } else {
      cout << "wrong\n";
    }
  }
  return 0;
}

bool is_right(int a, int b, int c) {
  int len[3];
  len[0] = a;
  len[1] = b;
  len[2] = c;

  sort(len, len + 3);

  if (len[2] * len[2] == len[1] * len[1] + len[0] * len[0])
    return true;
  else
    return false;
}
