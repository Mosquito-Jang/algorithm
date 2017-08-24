#include <stdio.h>

int n;
int dp[100001];
int max, a;

int main()
{
	scanf("%d", &n);

	for (int i = 1; i <= n; i++)
	{
		scanf("%d", &a);
		if (i == 1) max = a;

		if (dp[i - 1] + a > a) dp[i] = dp[i - 1] + a;
		else dp[i] = a;

		if (max < dp[i]) max = dp[i];
	}
	printf("%d", max);
}