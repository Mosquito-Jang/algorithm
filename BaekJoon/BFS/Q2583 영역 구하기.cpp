#include <stdio.h>
#include <queue>
#include <algorithm>

using namespace std;

int n, m, k;
int x_1, x_2, y_1, y_2;
bool arr[101][101];
bool visit[101][101];
int result[10001];

int bsf(int x, int y)
{
	int count = 1;

	queue<pair<int, int> > q;
	q.push(make_pair(x, y));

	visit[y][x] = 1;

	while (!q.empty())
	{
		int k_x = q.front().first;
		int k_y = q.front().second;

		q.pop();

		if (k_x >= 1 && !arr[k_y][k_x - 1] && !visit[k_y][k_x - 1])
		{
			visit[k_y][k_x - 1] = 1;
			q.push(make_pair(k_x - 1, k_y));
			count++;
		}

		if (k_x + 1 < m && !arr[k_y][k_x + 1] && !visit[k_y][k_x + 1])
		{
			visit[k_y][k_x + 1] = 1;
			q.push(make_pair(k_x + 1, k_y));
			count++;
		}

		if (k_y >= 1 && !arr[k_y - 1][k_x] && !visit[k_y - 1][k_x])
		{
			visit[k_y - 1][k_x] = 1;
			q.push(make_pair(k_x, k_y - 1));
			count++;
		}

		if (k_y + 1 < n && !arr[k_y + 1][k_x] && !visit[k_y + 1][k_x])
		{
			visit[k_y + 1][k_x] = 1;
			q.push(make_pair(k_x, k_y + 1));
			count++;
		}
	}
	return count;
}

int main()
{
	scanf("%d %d %d", &n, &m, &k);

	for (int i = 0; i < k; i++)
	{
		scanf("%d %d %d %d", &x_1, &y_1, &x_2, &y_2);

		for (int j = y_1; j < y_2; j++)
		{
			for (int z = x_1; z < x_2; z++)
			{
				if (!arr[j][z]) arr[j][z] = 1;
			}
		}
	}

	int cnt = 0;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (!arr[i][j] && !visit[i][j])
			{
				result[cnt++] = bsf(j, i);
			}
		}
	}
	sort(result, result + cnt);
	printf("%d\n", cnt);
	for (int i = 0; i < cnt; i++) printf("%d ", result[i]);
}