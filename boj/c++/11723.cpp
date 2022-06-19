#include <iostream>

using namespace std;

void set_command(int *arr, string c, int num);
int main(void)
{
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int M;
  int i;
  int arr[20];
  string command;
  int number;

  cin >> M;
  for (i = 0; i < 20; i++)
  {
    arr[i] = -1;
  }

  for (i = 0; i < M; i++)
  {
    cin >> command;
    if (!(command == "all" || command == "empty"))
      cin >> number;
    set_command(arr, command, number - 1);
  }
  return (0);
}

void set_command(int *arr, string c, int num) {
  if (c == "add")
    arr[num] = 1;
  else if (c == "remove")
    arr[num] = -1;
  else if (c == "check")
  {
    if (arr[num] > 0)
      cout << "1\n";
    else
      cout << "0\n";
  }
  else if (c == "toggle")
    arr[num] *= -1;
  else if (c == "all")
    for (int i = 0; i < 20; i++)
      arr[i] = 1;
  else if (c == "empty")
    for (int i = 0; i < 20; i++)
      arr[i] = -1;
}
