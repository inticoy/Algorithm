#include <iostream>
#include <string>

using namespace std;

int main(void) {
  string A, B;
  int lenA, lenB, i, current, temp;
  int prev = 0;
  string added("");

  cin >> A >> B;
  lenA = A.length();
  lenB = B.length();

  if (lenB > lenA) {
    swap(A, B);
    temp = lenB;
    lenB = lenA;
    lenA = temp;
  }

  for (i = 0; i < lenA; i++) {
    if (i >= lenB) {
      current = (A[lenA - i - 1] - '0') + prev;
      prev = current / 10;
      added = to_string(current % 10) + added;
    } else {
      current = (A[lenA - i - 1] - '0') + (B[lenB - i - 1] - '0') + prev;
      prev = current / 10;
      added = to_string(current % 10) + added;
    }
  }

  if (prev == 1) {
    added = "1" + added;
  }

  cout << added;

  return 0;
}
