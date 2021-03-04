#pragma warning(disable : 4996)
#include <iostream>
#include <cstring>
#include <vector>
#include <queue>
using namespace std;

vector<int> hh[401];
bool visited[401];
bool bfs(int n, int start, int end)
{
	visited[start] = true;
	queue<int> q;
	q.push(start);
	while (!q.empty())
	{
		int x = q.front(); q.pop();
		if (x == end) return true;
		for (int i = 0; i < hh[x].size(); i++) {
			int tmp = hh[x][i];
			if (visited[tmp] == false) {
				visited[tmp] = true;
				q.push(tmp);
			}
		}
	}
	return false;
}
int main()
{
	freopen("input.txt", "r", stdin);
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n, k, m;
	cin >> n >> k;
	while (k--) {
		int a, b;
		cin >> a >> b;
		hh[a].push_back(b);
	}
	cin >> m;
	while (m--) {
		int x, y;
		cin >> x >> y;
		memset(visited, false, sizeof(visited));
		if (bfs(n, x, y)) {
			cout << -1 << '\n';
			continue;
		}
		memset(visited, false, sizeof(visited));
		if (bfs(n, y, x))
			cout << 1 << '\n';
		else
			cout << 0 << '\n';
	}
}