#pragma warning(disable : 4996)
#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> v[10001];
int real[10001];
int visit[10001];
bool check[10001];
int dfs(int a)
{
	check[a] = true;
	int count = 0;
	for (int i = 0; i < v[a].size(); i++) {
		int tmp = v[a][i];
		if (check[tmp] == false) {
			count++;
			count += dfs(tmp);
		}
	}
	return count;
}
int main()
{
	freopen("input.txt", "r", stdin);
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n, m;
	cin >> n >> m;
	while (m--) {
		int a, b;
		cin >> a >> b;
		v[b].push_back(a);
	}
	int mx = 0;
	for (int i = 1; i <= n; i++) {
		memset(visit, 0, sizeof(visit));
		memset(check, false, sizeof(check));
		real[i] = dfs(i) + 1;
		if (mx < real[i])
			mx = real[i];
	}
	vector<int> mm;
	for (int i = 1; i <= n; i++) {
		if (real[i] == mx)
			mm.push_back(i);
	}
	sort(mm.begin(), mm.end());
	for (int i = 0; i < mm.size(); i++)
		cout << mm[i] << " ";
}