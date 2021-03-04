#pragma warning(disable : 4996)
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<int> metro[101001];
int visit[101001];
int bfs(int n, int a)
{
	visit[a] = 1;
	queue<int> q;
	q.push(a);
	while (!q.empty())
	{
		int x = q.front(); q.pop();
		if (x == n)
			return visit[x];
		for (unsigned int i = 0; i < metro[x].size(); i++) {
			int tmp = metro[x][i];
			if (visit[tmp] == 0) {
				q.push(tmp);
				if (tmp > n) // 더미 노드일 때는 그대로 진행
					visit[tmp] = visit[x];
				else  // 실제 노드이므로 +1을 해준다
					visit[tmp] = visit[x] + 1;
			}
		}
	}
	return -1;
}
int main()
{
	freopen("input.txt", "r", stdin);
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n, k, m;
	cin >> n >> k >> m;
	for (int i = 1; i <= m; i++) {
		for (int j = 0; j < k; j++) {
			int a;
			cin >> a;
			// 일종의 더미노드를 통해 하이퍼튜브 표현
			metro[i + n].push_back(a);
			metro[a].push_back(i + n);
		}
	}
	int ans = bfs(n, 1);
	cout << ans << endl;
}