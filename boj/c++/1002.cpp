#include <iostream>

using namespace std;

int main(void) {
  int n, i, x1, x2, y1, y2, r1, r2;
  int sqr_distance;
  int sqr_add;
  int sqr_diff;
  cin >> n;
  int answer[n];

  for (i = 0; i < n; i++) {
    cin >> x1 >> y1 >> r1 >> x2 >> y2 >> r2;
    if (x1 == x2 && y1 == y2) {
      if (r1 == r2) {
        answer[i] = -1;
      } else {
        answer[i] = 0;
      }
    } else {
      sqr_distance = (x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2);
      sqr_add = (r1 + r2) * (r1 + r2);
      sqr_diff = (r1 - r2) * (r1 - r2);
      if (sqr_distance > sqr_add) {
        answer[i] = 0;
      } else if (sqr_distance == sqr_add) {
        answer[i] = 1;
      } else {

        if (sqr_distance == sqr_diff) {
          answer[i] = 1;
        } else if (sqr_distance < sqr_diff) {
          answer[i] = 0;

        } else {
          answer[i] = 2;
        }
      }
    }
  }

  for (i = 0; i < n; i++) {
    cout << answer[i] << "\n";
  }

  return 0;
}
