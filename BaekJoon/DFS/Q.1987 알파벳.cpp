#include <stdio.h>
#include <vector>

using namespace std;

typedef struct check {
	bool c[30];
}check;

vector<pair<pair<int, int>, pair<check, int> > > v;


int R, C;
int arr[21][21];

int DFS(int x, int y)
{
	int max = 1;
	check visit;

	visit.c[arr[y][x]] = 1;

	v.push_back(make_pair(make_pair(0, 0), make_pair(visit, 1)));

	int f_x = v.back().first.first;
	int f_y = v.back().first.second;

	while (!v.empty())
	{
		int f_x = v.back().first.first;
		int f_y = v.back().first.second;
		check k = v.back().second.first;

		int cnt = v.back().second.second;

		v.pop_back();

		if (f_x - 1 >= 0 && arr[f_y][f_x] != arr[f_y][f_x - 1] && !k.c[arr[f_y][f_x - 1]])
		{
			check a = k;
			a.c[arr[f_y][f_x - 1]] = 1;
			v.push_back(make_pair(make_pair(f_x - 1, f_y), make_pair(a, cnt + 1)));
			if (cnt + 1> max) max = cnt + 1;
		}

		if (f_x + 1 < C && arr[f_y][f_x] != arr[f_y][f_x + 1] && !k.c[arr[f_y][f_x + 1]])
		{
			check a = k;
			a.c[arr[f_y][f_x + 1]] = 1;
			v.push_back(make_pair(make_pair(f_x + 1, f_y), make_pair(a, cnt + 1)));
			if (cnt + 1> max) max = cnt + 1;
		}

		if (f_y - 1 >= 0 && arr[f_y][f_x] != arr[f_y - 1][f_x] && !k.c[arr[f_y - 1][f_x]])
		{
			check a = k;
			a.c[arr[f_y - 1][f_x]] = 1;
			v.push_back(make_pair(make_pair(f_x, f_y - 1), make_pair(a, cnt + 1)));
			if (cnt + 1 > max) max = cnt + 1;
		}

		if (f_y + 1 < R && arr[f_y][f_x] != arr[f_y + 1][f_x] && !k.c[arr[f_y + 1][f_x]])
		{
			check a = k;
			a.c[arr[f_y + 1][f_x]] = 1;
			v.push_back(make_pair(make_pair(f_x, f_y + 1), make_pair(a, cnt + 1)));
			if (cnt + 1 > max) max = cnt + 1;
		}
	}

	return max;
}

int main()
{
	char c[21];
	scanf("%d %d", &R, &C);
	for (int i = 0; i < R; i++)
	{
		scanf("%s", &c);
		for (int j = 0; j < C; j++)
		{
			arr[i][j] = c[j] - 64;
		}
	}
	printf("%d", DFS(0, 0));
}