#include <iostream>
#include <string>

using namespace std;

int main(void){
  int i, len;
  string input;
  bool is_palindrome;

  while(true){
    cin >> input;
    if(input == "0") break;

    len = input.length();
    is_palindrome = true;

    for(i = 0; i < (len + 1) / 2; i++) {
      if (input[i] != input[len - 1 - i]) is_palindrome = false;
    }

    if (is_palindrome) cout << "yes" << endl;
    else cout << "no" << endl;
  }


  return 0;
}
