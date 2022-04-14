#include <iostream>

using namespace std;

int main(void) {
  int hour, min, more, nhour, nmin;

  cin >> hour >> min >> more;

  nhour = hour + (min + more) / 60;

  if (nhour >= 24)
    nhour -= 24;

  cout << nhour;
  cout << " " << (min + more) % 60;

  return 0;
}
