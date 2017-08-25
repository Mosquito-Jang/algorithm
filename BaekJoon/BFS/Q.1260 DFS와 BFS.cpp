#include <stdio.h>
#include <queue>

using namespace std;

int n, m, v, s, e;
queue <int> q;
bool connect[1001][1001];
bool dfs_visited[1001];
bool bfs_visited[1001];

int dfs(int f_s)
{
	if (f_s == v)
	{
		dfs_visited[f_s] = 1;
		printf("%d ", v);
	}
	for (int i = 1; i <= n; i++)
	{
		if (!dfs_visited[i] && connect[f_s][i])
		{
			printf("%d ", i);
			dfs_visited[i] = 1;
			dfs(i);
		}
	}	
	return 1;
}

int bfs(int f_s)
{
	bfs_visited[f_s] = 1;
	q.push(f_s);

	while (!q.empty())
	{
		int f_x = q.front();
		q.pop();
		printf("%d ", f_x);

		for (int i = 1; i <= n; i++)
		{
			if (!bfs_visited[i] && connect[f_x][i])
			{
				q.push(i);
				bfs_visited[i] = 1;
			}
		}
	}
	return 1;
}


int main()
{
	scanf("%d %d %d", &n, &m, &v);

	for (int i = 0; i < m; i++)
	{
		scanf("%d %d", &s, &e);
		connect[s][e] = 1;
		connect[e][s] = 1;
	}

	dfs(v);
	printf("\n");
	bfs(v);		
}