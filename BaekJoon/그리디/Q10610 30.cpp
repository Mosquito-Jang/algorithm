#include <stdio.h>
#include <algorithm>
#include <string.h>

using namespace std;

char str[100001];
int arr[100001];
int flag, n, sum;

bool compare(int &a, int &b)
{
	return a > b;
}

int main()
{
	scanf("%s", str);

	n = strlen(str);

	for (int i = 0; i < n; i++)
	{
		arr[i] = str[i] - '0';
		if (arr[i] == 0) flag = 1;
		sum += arr[i];
	}
	if (sum % 3 != 0) flag = 0;
	if (flag == 0) printf("-1");
	else
	{
		sort(arr, arr + n, compare);
		for (int i = 0; i < n; i++) printf("%d", arr[i]);
	}
}