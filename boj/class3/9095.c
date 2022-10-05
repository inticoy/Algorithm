#include <stdio.h>

int	solve(int n)
{
	if (n == 1)
		return (1);
	else if (n == 2)
		return (2);
	else if (n == 3)
		return (4);
	else
		return (solve(n - 3) + solve(n - 2) + solve(n - 1));
}

int	main(void)
{
	int	tests;
	int	i;
	int number;

	scanf("%d", &tests);
	i = 0;
	while (i < tests)
	{
		scanf("%d", &number);
		printf("%d\n", solve(number));
		i++;
	}
	return (0);
}
