// number = height * n
// height = 1

#include <iostream>

using namespace std;

int main(void) {
  int times, height, width, number, i;
  cin >> times;

  for (i = 0; i < times; i++) {
    cin >> height >> width >> number;
    if (number % height == 0)
      cout << height * 100 + ((number - 1) / height) + 1 << "\n";
    else
      cout << (number % height) * 100 + ((number - 1) / height) + 1 << "\n";
  }

  return 0;
}
