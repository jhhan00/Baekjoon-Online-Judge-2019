#pragma warning(disable : 4996)
#include <iostream>
#include <queue>
using namespace std;

int visit[101];
int nnext[101];

int bfs(int aa)
{
	queue<int> q;
	q.push(aa);
	visit[aa] = 0;
	while (!q.empty()) {
		int nw = q.front();
		q.pop();
		if (nw == 100)
			return visit[nw];
		for (int i = 1; i <= 6; i++) {
			int mv = nw + i;
			if (mv > 100) continue;
			mv = nnext[mv];
			if (visit[mv] == -1) {
				visit[mv] = visit[nw] + 1;
				q.push(mv);
			}
		}
	}
}

int main()
{
	freopen("input.txt", "r", stdin);
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n, m, a, b;
	for (int i = 1; i < 101; i++) {
		visit[i] = -1;
		nnext[i] = i;
	}
	cin >> n >> m;
	for (int i = 0; i < n+m; i++) {
		cin >> a >> b;
		nnext[a] = b;
	}	
	cout << bfs(1) << '\n';
}