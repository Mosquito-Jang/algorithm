#include <stdio.h>

int n = 1;
int arr[14];
int result[14];

int process(int cnt, int st)
{
	if (cnt > 5)
	{
		for (int i = 0; i < 6; i++) printf("%d ", result[i]);
		printf("\n");
		return 1;
	}

	for (int i = st; i < n; i++)
	{
		result[cnt] = arr[i];
		process(cnt + 1, i + 1);
	}

	return 0;
}

int main()
{
	while (1)
	{
		scanf("%d", &n);

		if (n == 0) break;

		for (int i = 0; i < n; i++) scanf("%d", &arr[i]);
		process(0, 0);
		printf("\n");
	}
}