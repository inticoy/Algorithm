#include <stdio.h>

long long padovan(int num);

int main(void)
{
  int n;
  int i;
  int num;

  scanf("%d", &n);
  i = 0;
  while (i < n)
  {
    scanf("%d", &num);
    printf("%lld\n", padovan(num));
    i++;
  }
  return (0);
}

long long padovan(int num)
{
  long long seq[num];
  int i;

  if (num == 1 || num == 2 || num == 3)
    return (1);
  else if (num == 4 || num == 5)
    return (2);
  else
  {
    seq[0] = 1;
    seq[1] = 1;
    seq[2] = 1;
    seq[3] = 2;
    seq[4] = 2;
    i = 5;
    while (i < num)
    {
      seq[i] = seq[i - 1] + seq[i - 5];
      i++;
    }
    return (seq[num - 1]);
  }
}
