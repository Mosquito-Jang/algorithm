#include <stdio.h>

int n, m;
int arr[510][510];
int dp[510][510];

int dfs(int x, int y)
{
	if (x == m && y == n) return 1;

	if (dp[y][x] == -1)
	{
		dp[y][x] = 0;
		if (x - 1 >= 1 && arr[y][x] > arr[y][x - 1])
		{
			dp[y][x] += dfs(x - 1, y);
		}
		if (x + 1 <= m && arr[y][x] > arr[y][x + 1])
		{
			dp[y][x] += dfs(x + 1, y);
		}
		if (y - 1 >= 1 && arr[y][x] > arr[y - 1][x])
		{
			dp[y][x] += dfs(x, y - 1);
		}
		if (y + 1 <= n && arr[y][x] > arr[y + 1][x])
		{
			dp[y][x] += dfs(x, y + 1);
		}
	}


	return dp[y][x];
}

int main()
{
	scanf("%d %d", &n, &m);

	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			scanf("%d", &arr[i][j]);
			dp[i][j] = -1;
		}
	}

	printf("%d", dfs(1, 1));
}