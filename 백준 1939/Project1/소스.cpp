#pragma warning(disable : 4996)
#include <iostream>
#include <queue>
#include <cstring>
#include <queue>
using namespace std;

vector<pair<int, long long>> mp[10001];
bool cn[10001];
int dx[] = { 0,0,-1,1 };
int dy[] = { -1,1,0,0 };
bool dfs(int x, int y, long long c)
{
	if (x == y) return true; // 끝점에 도착했을 때 true 리턴

	cn[x] = true; // 방문했다고 표시

	for (int i = 0; i < mp[x].size(); i++) {
		int nxt = mp[x][i].first;
		long long sz = mp[x][i].second;
		if (cn[nxt]==false && sz >= c) { // 방문하지 않고 중량제한도 지켰을 때
			if (dfs(nxt, y, c))
				return true;
		}
	}
	return false;
}
int main()
{
	freopen("input.txt", "r", stdin);
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	int n, m, start, end;
	cin >> n >> m;
	long long mx = 0;
	for (int i = 0; i < m; i++) {
		int a, b; long long c;
		cin >> a >> b >> c;
		mp[a].push_back({ b,c });
		mp[b].push_back({ a,c });
		if (c > mx)
			mx = c;
	}
	cin >> start >> end;
	long long left = 1, right = mx, mid;
	long long ans = 0;
	while (left <= right) {
		mid = (left + right) / 2;
		memset(cn, false, sizeof(cn));
		if (dfs(start, end, mid)) { // 건널 수 있음
			if (ans < mid)
				ans = mid;
			left = mid + 1;
		}
		else // 건널 수 없음
			right = mid - 1;
	}
	cout << ans << '\n';
}