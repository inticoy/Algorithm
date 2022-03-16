#include <iostream>

using namespace std;

int main(void){
  int n, i;

  cin >> n;
  int sequence[n];

  for (i = 0; i < n; i++){
    cin >> sequence[i];
  }

  int next_num = 1;
  int stack[n];
  int stack_len = 0;
  int top = -1;
  bool impossible = false;

  char answer[n * 2];
  int i_answer = 0;

  for (i = 0; i < n; i++){
    while(true){
      if (top < sequence[i]) {
        stack[stack_len] = next_num;
        top = next_num;
        next_num++;
        stack_len++;

        answer[i_answer] = '+';
        i_answer++;
      } else if (top == sequence[i]) {
        stack_len--;
        top = stack[stack_len - 1];

        answer[i_answer] = '-';
        i_answer++;
        break;
      } else {
        impossible = true;
        break;
      }
    }
    if(impossible){
      break;
    }
  }

  if (impossible) {
    cout << "NO";
  } else {
    for (i = 0; i < i_answer; i++){
      cout << answer[i] << "\n";
    }
  }


  return 0;
}
