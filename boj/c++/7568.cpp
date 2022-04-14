#include <iostream>

using namespace std;

int main(void) {
  int n, i, j;

  cin >> n;
  int info[n][2];
  int rank[n];
  for (i = 0; i < n; i++) {
    cin >> info[i][0] >> info[i][1];
    rank[i] = 1;
  }

  for (i = 0; i < n; i++) {
    for (j = 0; j < n; j++) {
      if (info[i][0] < info[j][0] && info[i][1] < info[j][1])
        rank[i]++;
    }
  }

  for (i = 0; i < n; i++) {
    cout << rank[i] << " ";
  }

  return 0;
}
