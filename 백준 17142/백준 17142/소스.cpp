#pragma warning(disable : 4996)
#include <iostream>
#include <cstring>
#include <vector>
#include <queue>
#define VALUE 2501
using namespace std;

int n, m, ans = VALUE;
int mp[50][50];
int np[50][50];
bool visit[50][50];
bool check[10];
vector<pair<int, int>> virus;
int bfs()
{
	int dx[] = { 0,0,-1,1 };
	int dy[] = { -1,1,0,0 };
	memset(np, -1, sizeof(np));
	memset(visit, false, sizeof(visit));
	queue<pair<int, int>> q;
	for (int i = 0; i < virus.size(); i++) {
		if (check[i]) {
			q.push(make_pair(virus[i].first, virus[i].second));
			np[virus[i].first][virus[i].second] = 0;
			visit[virus[i].first][virus[i].second] = true;
		}
	}

	int tt = 0;
	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		for (int k = 0; k < 4; k++) {
			int nx = x + dx[k];
			int ny = y + dy[k];
			if (nx >= 0 && nx < n && ny >= 0 && ny < n) {
				if (mp[nx][ny] == 1) continue; // 벽
				if (mp[nx][ny] == 2 && visit[nx][ny] == false) { // 비활성화 바이러스
					np[nx][ny] = np[x][y] + 1;
					visit[nx][ny] = true;
					q.push(make_pair(nx, ny));
				}
				if (mp[nx][ny] == 0 && visit[nx][ny] == false) { // 빈칸
					np[nx][ny] = np[x][y] + 1;
					visit[nx][ny] = true;
					q.push(make_pair(nx, ny));
					if (tt < np[nx][ny])
						tt = np[nx][ny];
				}
			}
		}
	}
	/*
	cout << tt << endl;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++)
			cout << np[i][j] << " ";
		cout << endl;
	}cout << endl;*/

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (mp[i][j] != 1 && np[i][j] == -1)
				return VALUE;
		}
	}

	return tt;
}
void make(int ix, int cnt)
{
	if (cnt == m) {
		int tmp = bfs();
		if (ans > tmp)
			ans = tmp;
		return;
	}
	for (int i = ix; i < virus.size(); i++) {
		if (check[i]) continue;
		check[i] = true;
		make(i + 1, cnt + 1);
		check[i] = false;
	}
}
int main()
{
	freopen("input.txt", "r", stdin);
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> mp[i][j];
			if (mp[i][j] == 2)
				virus.push_back(make_pair(i, j));
		}
	}

	make(0, 0);
	if (ans == VALUE)
		cout << -1 << endl;
	else
		cout << ans << endl;
}