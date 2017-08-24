#include <stdio.h>
#include <algorithm>

using namespace std;

int l, c;
char arr[16];
char check[6] = { 'a','e','i','o','u' };
char result[16];

int process(int cnt, int st)
{
	int m_count = 0;

	if (cnt >= l)
	{
		for (int i = 0; i < l; i++)
		{
			for (int j = 0; j < 6; j++)
			{
				if (check[j] == result[i])
				{
					m_count++;
					j = 6;
				}
			}
		}
		if (m_count >= 1 && l - m_count >= 2)
		{
			for (int i = 0; i < l; i++) printf("%c", result[i]);
			printf("\n");
		}
		return 1;
	}
	for (int i = st; i < c; i++)
	{
		result[cnt] = arr[i];
		process(cnt + 1, i + 1);
	}
	return 0;
}

int main()
{
	scanf("%d %d", &l, &c);

	for (int i = 0; i < c; i++)
	{
		scanf(" %c", &arr[i]);
	}
	
	sort(arr, arr + c);

	process(0, 0);


}