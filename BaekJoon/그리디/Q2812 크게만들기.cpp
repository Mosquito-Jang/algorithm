#include <stdio.h>
#include <deque>

using namespace std;
char str[500001];
int arr[500001];
deque <int> d;

int main()
{
	int m, n;

	scanf("%d %d", &m, &n);

	scanf("%s", str);

	for (int i = 0; i < m; i++) arr[i] = str[i] - '0';

	for (int i = 0; i < n; i++)
	{
		while (!d.empty() && d.back() < arr[i]) d.pop_back();
		d.push_back(arr[i]);
	}
	for (int i = n; i < m; i++)
	{
		while (!d.empty() && d.back() < arr[i]) d.pop_back();
		d.push_back(arr[i]);
		printf("%d", d.front());
		d.pop_front();
	}
}