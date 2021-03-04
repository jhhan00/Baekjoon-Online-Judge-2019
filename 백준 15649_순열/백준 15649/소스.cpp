#pragma warning(disable : 4996)
#include <iostream>
#include <vector>
using namespace std;

int n, m;
int a[8];
int visit[8];
vector<int> v;

void dfs()
{
	int i;
	if (v.size() == m) {
		for (i = 0; i < m; i++)
			printf("%d ", v[i]);
		printf("\n");
		return;
	}
	for (i = 0; i < n; i++) {
		if (visit[i])
			continue;
		visit[i] = 1;
		v.push_back(a[i]);
		dfs();
		v.pop_back();
		visit[i] = 0;
	}
}

int main()
{
	cin >> n >> m;
	for (int i = 0; i < n; i++)
		a[i] = i + 1;
	dfs();
}