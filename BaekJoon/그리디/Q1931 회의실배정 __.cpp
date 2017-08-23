#include <stdio.h>
#include <algorithm>
#include <vector>

using namespace std;

typedef struct a {
	int s, e;
}u_a;

int n, m;
u_a arr[100001];
vector<pair <int, int> >v;

bool compare(u_a &a, u_a &b)
{
	if (a.s < b.s) return 1;
	if (a.s == b.s && a.e < b.e) return 1;
	else return 0;
}

int main()
{
	scanf("%d", &n);
	for (int i = 0; i < n; i++) scanf("%d %d", &arr[i].s, &arr[i].e);

	sort(arr, arr + n, compare);

	v.push_back(make_pair(arr[0].s, arr[0].e));

	for (int i = 1; i < n; i++)
	{
		if (v.back().second > arr[i].e)
		{
			v.pop_back();
			v.push_back(make_pair(arr[i].s, arr[i].e));
		}
		else if (v.back().second <= arr[i].s) v.push_back(make_pair(arr[i].s, arr[i].e));
	}

	printf("%d", v.size());

}