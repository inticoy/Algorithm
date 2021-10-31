#include <stdio.h>

int LinearSearch(int ar[], int len, int target)
{
  for(int i = 0; i < len; i++)
  {
    if(ar[i] == target)
      return i;
  }
  return -1;
}

int main(void)
{
  int arr[] = {3, 5, 2, 4, 9};
  int idx;

  idx = LinearSearch(arr, sizeof(arr)/sizeof(int), 4);
  if(idx == -1)
    printf("Search Failed\n");
  else
    printf("Target Index: %d \n", idx);

  idx = LinearSearch(arr, sizeof(arr)/sizeof(int), 7);
  if(idx == -1)
    printf("Search Failed\n");
  else
    printf("Target Index: %d \n", idx);

  return 0;
}
