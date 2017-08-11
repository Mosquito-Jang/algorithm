#include <stdio.h>

int dp[3001];
int arr[1001];
int n;

int main()
{
	scanf("%d", &n);

	for (int i = 1; i <= n; i++)
	{
		scanf("%d", &arr[i]);
		dp[i] = 99999;
	}

	dp[1] = 0;

	bool flag = 0;

	for (int i = 1; i <= n; i++)
	{
		if (dp[i] == 99999) continue;
		for (int j = arr[i]; j >= 1; j--)
		{
			if (dp[i + j] > dp[i] + 1)
			{
				dp[i + j] = dp[i] + 1;
				if (i + j == n)
				{
					flag = 1;
					break;
				}
			}
		}
		if (flag == 1) break;
	}
	if (dp[n] == 99999) printf("-1");
	else printf("%d", dp[n]);
}