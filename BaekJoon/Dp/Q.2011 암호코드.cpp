#include <stdio.h>
#include <string.h>

int arr[5001];
int dp[5001];

int main()
{
	char c[5000];
	int n;

	scanf("%s", c);
	n = strlen(c);

	for (int i = 1; i <= n; i++) arr[i] = c[i - 1] - '0';

	if (arr[1] == 0) printf("0");

	else
	{
		dp[0] = 1;
		dp[1] = 1;
		for (int i = 2; i <= n; i++)
		{
			if (arr[i] > 0) dp[i] = (dp[i] + dp[i - 1]) % 1000000;

			if (arr[i - 1] * 10 + arr[i] >= 10 && arr[i - 1] * 10 + arr[i] <= 26)
			{
				dp[i] = (dp[i] + dp[i - 2]) % 1000000;
			}
		}
		printf("%d", dp[n]);
	}
}