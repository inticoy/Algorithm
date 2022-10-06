#include <stdio.h>
#include <stdlib.h>

char	**set_char_arr_2d(int n)
{
	char	**ret;
	int		i;
	int		j;

	ret = (char **) malloc(sizeof(char *) * (n + 1));
	i = 0;
	while (i < n + 1)
	{
		j = 0;
		ret[i] = (char *) malloc(sizeof(char) * (n + 1));
		while (j < n + 1)
			ret[i][j++] = 0;
		i++;
	}
	return (ret);
}

char	*set_visited(int n)
{
	int		i;
	char	*ret;

	i = 0;
	ret = (char *) malloc(sizeof(char) * (n + 1));
	while (i < n + 1)
		ret[i++] = 0;
	return (ret);
}

void	free_matrix(char **arr, int n)
{
	int	i;

	i = 0;
	while (i < n)
		free(arr[i++]);
	free(arr);
}

void	DFS(char **m, char *visited, int n, int v)
{
	int	i;
	if (visited[v] == 0)
	{
		printf("%d ", v);
		visited[v] = 1;
	}
	i = 1;
	while (i < n + 1)
	{
		if (m[v][i] || m[i][v])
			DFS(m, visited, n, i);
		i++;
	}
}


int	main(void)
{
	int		condition[3];
	int		input[2];
	int		i;
	char	**adj_matrix;
	char	*visited;

	scanf("%d %d %d", condition, condition + 1, condition + 2);
	getchar();
	adj_matrix = set_char_arr_2d(condition[0]);
	i = 0;
	while (i < condition[1])
	{
		scanf("%d %d", input, input + 1);
		getchar();
		adj_matrix[input[0]][input[1]] = 1;
		i++;
	}
	visited = set_visited(condition[0]);
	i = 0;
	while (i < condition[0])
		printf("%d ", visited[i++]);
	DFS(adj_matrix, visited, condition[0], condition[2]);
	i = 0;
	while (i < condition[0] + 1)
		visited[i++] = 0;
	//BFS(adj_matrix, visited, condition[0]);
	free(visited);
	free_matrix(adj_matrix, condition[0] + 1);
	return (0);
}
