#include <stdio.h>
#include <stdlib.h>


int n, m, a;
int k;
bool check[50001];
bool temp[50001];

int main()
{
	scanf("%d", &n);

	check[0] = 1;

	for (int i = 0; i < n; i++)
	{
		scanf("%d", &k);

		for (int j = 0; j <= 15000; j++)
		{
			if (check[j] == 1)
			{
				int l = abs(k - j);
				int r = abs(k + j);

				if (l <= 15000) temp[l] = 1;
				if (r <= 15000) temp[r] = 1;
			}
		}
		for (int j = 0; j <= 15000; j++)
		{
			if (temp[j] == 1) check[j] = 1;
		}
	}

	scanf("%d", &m);

	for (int i = 0; i < m; i++)
	{
		scanf("%d", &a);
		if (check[a] == 1) printf("Y ");
		else printf("N ");
	}
}