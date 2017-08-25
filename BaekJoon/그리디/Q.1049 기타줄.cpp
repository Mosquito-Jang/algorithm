#include <stdio.h>

int n, m, a, b, x, y;
int min_w = 999999999;
int min_i = 999999999;
int price;

int main()
{
	scanf("%d %d", &n, &m);

	for (int i = 0; i < m; i++)
	{
		scanf("%d %d", &a, &b);

		if (a < min_w) min_w = a;
		if (b < min_i) min_i = b;
	}
	int quo = n / 6;
	int rest = n % 6;

	if (min_w < min_i * rest) price = (quo + 1) * min_w;
	else if (min_w > min_i * 6) price = min_i * n;
	else
	{
		price = quo * min_w;
		price += rest * min_i;
	}

	printf("%d", price);
}