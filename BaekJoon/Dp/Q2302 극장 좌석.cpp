#include <stdio.h>

int dp[41];
int arr[41];
int n, k, m;

int main()
{
	scanf("%d", &n);
	scanf("%d", &m);

	dp[0] = 1;
	dp[1] = 1;
	for (int i = 0; i < m; i++)
	{
		scanf("%d", &k);
		arr[k] = 1;
	}

	for (int i = 2; i <= n; i++) dp[i] = dp[i - 1] + dp[i - 2];

	int s = 1;
	int result = 1;

	for (int i = 1; i <= n; i++)
	{
		if (arr[i] == 1)
		{
			result *= dp[i - s];
			s = i + 1;
		}
		else if (i == n) result *= dp[i - s + 1];
	}

	printf("%d", result);
}