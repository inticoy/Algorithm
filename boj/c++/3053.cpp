#include <iostream>
#define PI 3.14159265358979323846
using namespace std;

int main(void) {
  double n;
  cin >> n;

  cout << fixed;
  cout.precision(6);
  cout << n * n * PI << "\n";
  cout << n * n * 2;

  return 0;
}
