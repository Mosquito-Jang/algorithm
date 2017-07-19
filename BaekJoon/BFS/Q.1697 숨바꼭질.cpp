#include <stdio.h>
#include <queue>
#include <algorithm>

using namespace std;
queue<pair<int, int> > q;
bool check[100003];

int main()
{
	int n, k;

	scanf("%d %d", &n, &k);

	q.push(make_pair(n, 0));

	check[n] = 1;

	while (!q.empty())
	{
		int a = q.front().first;
		int b = q.front().second;


		if (a == k)
		{
			printf("%d\n", b);
			break;
		}

		q.pop();

		if (a - 1 >= 0 && check[a - 1] == 0)
		{
			q.push(make_pair(a - 1, b + 1));
			check[a - 1] = 1;
		}
		if (a + 1 <= 100000 && check[a + 1] == 0)
		{
			q.push(make_pair(a + 1, b + 1));
			check[a + 1] = 1;
		}
		if (a * 2 <= 100000 && check[a * 2] == 0)
		{
			q.push(make_pair(a * 2, b + 1));
			check[a * 2] = 1;
		}
	}
}