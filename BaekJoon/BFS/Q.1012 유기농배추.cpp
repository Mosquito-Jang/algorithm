#include <stdio.h>
#include <queue>
#include <string.h>

using namespace std;

int T;
int x, y, k;
int a, b;
bool arr[51][51];
bool check[51][51];
int cnt;

queue<pair<int, int> > q;

void bfs(int f_x, int f_y)
{
	q.push(make_pair(f_x, f_y));

	while (!q.empty())
	{
		int q_x = q.front().first;
		int q_y = q.front().second;

		q.pop();

		if (q_x - 1 >= 1 && arr[q_y][q_x - 1] && !check[q_y][q_x - 1])
		{
			q.push(make_pair(q_x - 1, q_y));
			check[q_y][q_x - 1] = 1;
		}
		if (q_x + 1 <= x && arr[q_y][q_x + 1] && !check[q_y][q_x + 1])
		{
			q.push(make_pair(q_x + 1, q_y));
			check[q_y][q_x + 1] = 1;
		}
		if (q_y - 1 >= 1 && arr[q_y - 1][q_x] && !check[q_y - 1][q_x])
		{
			q.push(make_pair(q_x, q_y - 1));
			check[q_y - 1][q_x] = 1;
		}
		if (q_y + 1 <= y && arr[q_y + 1][q_x] && !check[q_y + 1][q_x])
		{
			q.push(make_pair(q_x, q_y + 1));
			check[q_y + 1][q_x] = 1;
		}
		//printf("%d %d\n",q_x,q_y );
	}
}

int main()
{
	scanf("%d", &T);

	for (int z = 0; z < T; z++)
	{
		scanf("%d %d %d", &x, &y, &k);

		memset(check, 0, sizeof(check));
		memset(arr, 0, sizeof(arr));

		for (int i = 1; i <= k; i++)
		{
			scanf("%d %d", &a, &b);
			arr[b + 1][a + 1] = 1;
		}

		for (int i = 1; i <= y; i++)
		{
			for (int j = 1; j <= x; j++)
			{
				if (arr[i][j] && !check[i][j])
				{
					check[i][j] = 1;
					bfs(j, i);
					//printf("%d\n", cnt);
					cnt++;
				}
			}
		}
		printf("%d\n", cnt);
		cnt = 0;
	}
}