#include <stdio.h>
#include <queue>

using namespace std;

int arr[501][101];
int visited[501][101];
queue<pair<int, int> > q;

int main()
{
	int n, m;
	int i, j;
	char c[1000];

	scanf("%d %d", &n, &m);

	for (i = 0; i < n; i++)
	{
		scanf("%s", &c);
		for (j = 0; j < m; j++)
		{
			arr[i][j] = c[j] - 48;
		}
	}

	q.push(make_pair(0, 0)); //first x, second y

	visited[0][0] = 1;

	while (!q.empty())
	{
		int x = q.front().first;
		int y = q.front().second;

		q.pop();

		if (arr[y][x + 1] >= 1 && visited[y][x + 1] == 0 && x + 1 < m)
		{
			q.push(make_pair(x + 1, y));
			visited[y][x + 1] += visited[y][x] + 1;
		}
		if (arr[y][x - 1] >= 1 && visited[y][x - 1] == 0 && x >= 1)
		{
			q.push(make_pair(x - 1, y));
			visited[y][x - 1] += visited[y][x] + 1;
		}
		if (arr[y + 1][x] >= 1 && visited[y + 1][x] == 0 && y + 1 < n)
		{
			q.push(make_pair(x, y + 1));
			visited[y + 1][x] += visited[y][x] + 1;
		}
		if (arr[y - 1][x] >= 1 && visited[y - 1][x] == 0 && y >= 1)
		{
			q.push(make_pair(x, y - 1));
			visited[y - 1][x] += visited[y][x] + 1;
		}
		//printf("%d %d\n", x, y);
		//printf("%d\n", visited[x][y]);
	}
	printf("%d\n", visited[n - 1][m - 1]);

}