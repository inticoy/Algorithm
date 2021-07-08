#include <iostream>

using namespace std;
int main(void)
{
  int T, k, n, i; // variables for problem
  int people, x, y; // variables for adding
  cin >> T;

  for (i = 0; i < T; i++) {
    cin >> k;
    cin >> n;
    people = 0;
    y = k + 1;

    for (x = 1; x <= n; x++){
      // people += x * y;
      // y--;
      // cout << "people: " << people << endl;
    }

    cout << people << endl;
  }

  return 0;
}
