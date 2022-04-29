#include <iostream>

using namespace std;

int arr[100];

int fib(int n){
  if (n == -1){
    return 1;
  } else if (n == 0){
    return 0;
  } else if (n == 1){
    return 1;
  } else if (arr[n] != 0){
    return arr[n];
  } else {
    arr[n] = fib(n - 1) + fib(n - 2);
    return arr[n];
  }
}

int main(void){
  int n, i, x;
  cin >> n;
  for (i = 0; i < n; i++){
    cin >> x;
    cout << fib(x - 1) << " " << fib(x) << "\n";
  }

  return 0;
}
