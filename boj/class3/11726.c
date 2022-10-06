#include <stdio.h>

int main(void)
{
	int	helper[3];
	int	n;
	int	i;

	helper[0] = 0;
	helper[1] = 1;
	helper[2] = 1;
	scanf("%d", &n);
	i = 2;
	while (i <= n)
	{
		helper[0] = helper[1];
		helper[1] = helper[2];
		helper[2] = (helper[0] + helper[1]) % 10007;
		i++;
	}
	printf("%d", helper[2]);
	return (0);
}
