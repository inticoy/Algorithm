#include <stdio.h>
#include <stdlib.h>

void solved(int *baord, int solved, int *count, int number);

int is_valid_row(int *board, int number) {
  int *check;
  int i;

  check = (int *)malloc(sizeof(int) * number);
  i = 0;
  while (i < number)
    check[i++] = 0;
  i = 0;
  while (i < number) {
    if (board[i] != -1)
      check[board[i]]++;
    i++;
  }
  i = 0;
  while (i < number) {
    if (check[i] > 1) {
      free(check);
      return (0);
    }
    i++;
  }
  free(check);
  return (1);
}

int is_valid_diagonal(int *board, int number) {
  int i;
  int j;

  i = 0;
  while (i < number - 1) {
    j = 1;
    while (j < number - i) {
      if (board[i] != -1 && board[i + j] != -1) {
        if (board[i] == board[i + j] + j)
          return (0);
        if (board[i] + j == board[i + j])
          return (0);
      }
      j++;
    }
    i++;
  }
  return (1);
}

void solve(int *board, int solved, int *count, int number) {
  int i;

  i = 0;
  if (solved == number) {
    *count = *count + 1;
  } else {
    while (i < number) {
      board[solved] = i;
      if (is_valid_row(board, number) == 1 &&
          is_valid_diagonal(board, number) == 1)
        solve(board, solved + 1, count, number);
      board[solved] = -1;
      i++;
    }
  }
}

int ten_queens_puzzle(int number) {
  int *board;
  int count;
  int i;

  board = (int *)malloc(sizeof(int) * number);
  i = 0;
  count = 0;
  while (i < number) {
    board[i] = -1;
    i++;
  }
  solve(board, 0, &count, number);
  free(board);
  board = 0;
  return (count);
}

int main(void) {
  int answer;

  answer = 0;
  scanf("%d", &answer);
  printf("%d\n", ten_queens_puzzle(answer));
  return (0);
}
