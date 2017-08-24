#include <stdio.h>

typedef struct c {
	int x, y;
}c;

int arr[9][9];
c zero[84];
int k;

int process(int cnt)
{
	bool check[10] = { 0, };

	int f_x = zero[cnt].x;
	int f_y = zero[cnt].y;
	int s_x, s_y;

	if (cnt > k)
	{
		for (int i = 0; i < 9; i++)
		{
			for (int j = 0; j < 9; j++) printf("%d ", arr[i][j]);
			printf("\n");
		}
		return 1;
	}

	for (int i = 0; i < 9; i++)
	{
		if (arr[f_y][i] != 0) check[arr[f_y][i]] = 1;
		if (arr[i][f_x] != 0) check[arr[i][f_x]] = 1;
	}

	if (f_x <= 2) s_x = 0;
	else if (f_x <= 5) s_x = 3;
	else if (f_x <= 8) s_x = 6;
	if (f_y <= 2) s_y = 0;
	else if (f_y <= 5) s_y = 3;
	else if (f_y <= 8) s_y = 6;

	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			if (arr[s_y + i][s_x + j] != 0) check[arr[s_y + i][s_x + j]] = 1;
		}
	}

	for (int i = 1; i <= 9; i++)
	{
		if (check[i] == 0)
		{
			arr[f_y][f_x] = i;
			process(cnt + 1);
			arr[f_y][f_x] = 0;
		}
	}
	return 0;
}

int main()
{
	for (int i = 0; i < 9; i++)
	{
		for (int j = 0; j < 9; j++)
		{
			scanf("%d", &arr[i][j]);
			if (arr[i][j] == 0)
			{
				zero[++k].x = j;
				zero[k].y = i;
			}
		}
	}
	process(1);
}