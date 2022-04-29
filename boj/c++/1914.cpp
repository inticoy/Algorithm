#include <iostream>

using namespace std;

string pow2minus1(int times){
  int i, j, len, temp;
  int up = 0;
  string ret = "1";
  for (i = 0; i < times; i++){
    up = 0;
    len = ret.length();
    for (j = len - 1; j >= 0; j--){
      temp = (ret[j] - '0') * 2;
      ret[j] = (temp % 10 + up) + '0';
      up = temp / 10;
    }
    if (up == 1){
      ret = "1" + ret;
    }
  }
  len = ret.length();
  ret[len-1] = ret[len-1] - 1;
  return ret;
}

void hanoi(int num, int from, int to, int left);

int main(void){
  int n;
  cin >> n;
  cout << pow2minus1(n) << "\n";
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
