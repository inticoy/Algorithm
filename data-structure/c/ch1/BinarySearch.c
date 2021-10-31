#include <stdio.h>

int BinarySearch(int ar[], int len, int target)
{
  int start = 0;
  int end = len - 1;
  int middle;

  while(start <= end)
  {
    
  }


}

int main()
{
  int arr[] = {1, 3, 5, 7, 9};
  int idx;

  idx = BinarySearch(arr, sizeof(arr)/sizeof(int), 4);
  if(idx == -1)
    printf("Search Failed\n");
  else
    printf("Target Index: %d \n", idx);

  idx = BinarySearch(arr, sizeof(arr)/sizeof(int), 7);
  if(idx == -1)
    printf("Search Failed\n");
  else
    printf("Target Index: %d \n", idx);


  return 0;
}
