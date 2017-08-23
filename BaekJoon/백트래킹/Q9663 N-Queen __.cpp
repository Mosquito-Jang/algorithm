#include <stdio.h>
#include <string.h>

int n;
bool x[16];
bool c_1[32];
bool c_2[32];
int count;

int process(int f_y)
{
	if (f_y >= n)
	{
		count++;
		return 1;
	}

	for (int i = 0; i < n; i++)
	{
		if (x[i] || c_1[f_y + i] || c_2[n + f_y - i]) continue;

		x[i] = 1;
		c_1[f_y + i] = 1;
		c_2[n + f_y - i] = 1;

		process(f_y + 1);

		x[i] = 0;
		c_1[f_y + i] = 0;
		c_2[n + f_y - i] = 0;
	}
}

int main()
{
	scanf("%d", &n);

	process(0);

	printf("%d", count);
}

