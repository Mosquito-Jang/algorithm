#include <stdio.h>
#include <queue>

#define MAX(a,b) ((a) > (b)) ? (a) : (b)

using namespace std;

int arr[1001][1001];
int check;
int cnt[1001][1001];
queue<pair<int, int> > q;

int main()
{
	int x, y;
	int s_x, s_y, max = 0;
	int flag = 0;

	scanf("%d %d", &x, &y);

	for (int i = 1; i <= y; i++)
	{
		for (int j = 1; j <= x; j++)
		{
			scanf("%d", &arr[i][j]);
			if (arr[i][j] == 1)
			{
				q.push(make_pair(j, i));
			}
		}
	}

	while (!q.empty())
	{
		int a = q.front().first;  //x 
		int b = q.front().second; //y

		q.pop();

		if (a - 1 >= 1 && arr[b][a - 1] == 0)
		{
			arr[b][a - 1] = 1;
			q.push(make_pair(a - 1, b));
			cnt[b][a - 1] += (cnt[b][a] + 1);
			if (cnt[b][a - 1] > max) max = cnt[b][a - 1];
		}
		if (a + 1 <= x && arr[b][a + 1] == 0)
		{
			arr[b][a + 1] = 1;
			q.push(make_pair(a + 1, b));
			cnt[b][a + 1] += (cnt[b][a] + 1);
			if (cnt[b][a + 1] > max) max = cnt[b][a + 1];
		}
		if (b - 1 >= 1 && arr[b - 1][a] == 0)
		{
			arr[b - 1][a] = 1;
			q.push(make_pair(a, b - 1));
			cnt[b - 1][a] += (cnt[b][a] + 1);
			if (cnt[b - 1][a] > max) max = cnt[b - 1][a];
		}
		if (b + 1 <= y && arr[b + 1][a] == 0)
		{
			arr[b + 1][a] = 1;
			q.push(make_pair(a, b + 1));
			cnt[b + 1][a] += (cnt[b][a] + 1);
			if (cnt[b + 1][a] > max) max = cnt[b + 1][a];
		}

	}
	for (int i = 1; i <= y; i++)
	{
		for (int j = 1; j <= x; j++)
		{
			//printf("%d ", arr[i][j]);
			if (arr[i][j] == 0)
			{
				printf("-1");
				flag = 1;
				break;
			}
		}
		//printf("\n");
	}
	if (flag == 0) printf("%d", max);
}