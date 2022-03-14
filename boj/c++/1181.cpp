#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

bool mycompare(const string &a, const string &b){
  int lena = a.length();
  int lenb = b.length();
  int i;
  if (lena < lenb){
    return true;
  } else if (lena > lenb){
    return false;
  } else {
    // can change by string.compare
    for(i = 0; i < lena; i++){
      if (a[i] < b[i]){
        return true;
      } else if (a[i] > b[i]) {
        return false;
      }
    }
  }
  return false;

}

int main(void){
  int total, i, j;
  string before;
  cin >> total;

  string words[total];

  for (i = 0; i < total; i++) {
    cin >> words[i];
  }

  sort(words, words+total, mycompare);

  for (i = 0; i < total; i++) {
    if (before != words[i]) cout << words[i] << endl;
    before = words[i];
  }

  return 0;
}
