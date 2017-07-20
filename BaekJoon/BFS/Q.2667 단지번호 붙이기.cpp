#include <stdio.h>
#include <queue>
#include <stdlib.h>

using namespace std;

bool arr[26][26];
bool check[26][26];
int k[1000];

queue<pair<int, int> > q;

int n;

int cmp(const void *pa, const void *pb)
{
	if (*(int*)pa > *(int*)pb) return 1;
	else if (*(int*)pa < *(int*)pb) return -1;
	else return 0;
}

int bsf(int x, int y)
{
	int cnt = 1;
	q.push(make_pair(x, y));

	while (!q.empty())
	{
		int f_x = q.front().first;
		int f_y = q.front().second;

		q.pop();

		if (f_x - 1 >= 1 && !check[f_y][f_x - 1] && arr[f_y][f_x - 1])
		{
			q.push(make_pair(f_x - 1, f_y));
			check[f_y][f_x - 1] = true;
			cnt++;
		}
		if (f_x + 1 <= n && !check[f_y][f_x + 1] && arr[f_y][f_x + 1])
		{
			q.push(make_pair(f_x + 1, f_y));
			check[f_y][f_x + 1] = true;
			cnt++;
		}
		if (f_y - 1 >= 1 && !check[f_y - 1][f_x] && arr[f_y - 1][f_x])
		{
			q.push(make_pair(f_x, f_y - 1));
			check[f_y - 1][f_x] = true;
			cnt++;
		}
		if (f_y + 1 <= n && !check[f_y + 1][f_x] && arr[f_y + 1][f_x])
		{
			q.push(make_pair(f_x, f_y + 1));
			check[f_y + 1][f_x] = true;
			cnt++;
		}
	}
	return cnt;
}



int main()
{
	int result = 0;
	char str[26];

	scanf("%d", &n);

	for (int i = 1; i <= n; i++)
	{
		scanf("%s", &str);
		for (int j = 1; j <= n; j++)
		{
			arr[i][j] = str[j - 1] - 48;
		}
	}


	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			if (arr[i][j] && !check[i][j])
			{
				check[i][j] = true;
				k[result++] = bsf(j, i);
			}
		}
	}
	printf("%d\n", result);
	qsort(k, result, sizeof(result), cmp);
	for (int i = 0; i < result; i++) printf("%d\n", k[i]);
}