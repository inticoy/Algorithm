#include <stdio.h>
#include <limits.h>
#include <stdlib.h>

int	get_min(int *arr, int len)
{
	int	i;
	int	min;

	i = 0;
	min = INT_MAX;
	while (i < len)
	{
		if (arr[i] < min)
			min = arr[i];
		i++;
	}
	return (min);
}

int	make_one(int *arr, int x)
{
	int	ret[3];

	ret[0] = INT_MAX;
	ret[1] = INT_MAX;
	ret[2] = INT_MAX;
	if (arr[x] != -1)
		return (arr[x]);
	if (x % 3 == 0)
		ret[0] = make_one(arr, x / 3) + 1;
	if (x % 2 == 0)
		ret[1] = make_one(arr, x / 2) + 1;
	ret[2] = make_one(arr, x - 1) + 1;
	arr[x] = get_min(ret, 3);
	return (arr[x]);
}		

int	main(void)
{
	int	x;
	int	i;
	int	*arr;

	scanf("%d", &x);
	arr = (int *) malloc(sizeof(int) * (x + 1));
	i = 0;
	while (i < x + 1)
		arr[i++] = -1;
	arr[1] = 0;
	printf("%d", make_one(arr, x));
	return (0);
}
