#include <iostream>

using namespace std;

int main(void){
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  
  int n, m, input, i, j, it;
  cin >> n >> m;

  int arr[n];

  for(it = 0; it < n; it++){
    cin >> input;
    if (it == 0) {
      arr[it] = input;
    } else {
      arr[it] = input + arr[it - 1];
    }
  }



  for (it = 0; it < m; it++) {
    cin >> i >> j;
    if (i == 1){
      cout << arr[j - 1] << "\n";
    } else {
      cout << arr[j - 1] - arr[i - 2] << "\n";
    }
  }
  return 0;
}
