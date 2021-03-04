#pragma warning(disable : 4996)
#include <iostream>
#include <vector>
#include <cstring>
#include <queue>
using namespace std;

vector<int> fr[101];
bool visit[101];
int vs[101];
int bacon[101];
void bfs(int start)
{
	queue<int> q;
	q.push(start);
	visit[start] = true;
	vs[start] = 0;
	while (!q.empty()) {
		int x = q.front(); q.pop();
		for (int i = 0; i < fr[x].size(); i++) {
			int tmp = fr[x][i];
			if (visit[tmp] == false && vs[tmp] == -1) {
				visit[tmp] = true;
				vs[tmp] = vs[x] + 1;
				q.push(tmp);
			}
		}
	}
}
int main()
{
	freopen("input.txt", "r", stdin);
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n, m, minip, mini;
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		fr[a].push_back(b);
		fr[b].push_back(a);
	}
	minip = 999999;
	mini = 1000;
	for (int i = 1; i <= n; i++) {
		memset(visit, false, sizeof(visit));
		memset(vs, -1, sizeof(vs));
		bfs(i);
		for (int j = 1; j <= n; j++)
			bacon[i] += vs[j];
		if (minip > bacon[i]) {
			minip = bacon[i];
			mini = i;
		}
	}
	cout << mini << '\n';
}