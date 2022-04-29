#include <iostream>

using namespace std;

void hanoi(int num, int from, int to, int left);

int main(void){
  int n;
  cin >> n;
  cout << (1 << n) - 1 << "\n";
  if (n <= 20){
    hanoi(n, 1, 3, 2);
  }
  return 0;
}

void hanoi(int num, int from, int to, int left){
  if (num == 1) {
    cout << from << " " << to << "\n";
  } else {
    hanoi(num - 1, from, left, to);
    cout << from << " " << to << "\n";
    hanoi(num - 1, left, to, from);
  }
}
