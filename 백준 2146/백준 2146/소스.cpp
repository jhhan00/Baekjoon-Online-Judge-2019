#pragma warning(disable : 4996)
#include <iostream>
#include <cstring>
#include <queue>
using namespace std;

int n;
int mp[101][101];
int island[101][101];
bool visit[101][101];
int dari[101][101];
int dx[] = { 0,0,-1,1 };
int dy[] = { -1,1,0,0 };
int make_bridge(int a, int b)
{
	int bridge = 10001;
	memset(visit, false, sizeof(visit));
	memset(dari, 0, sizeof(dari));
	queue<pair<int, int>> q;
	q.push(make_pair(a, b));
	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		for (int k = 0; k < 4; k++) {
			int nx = x + dx[k];
			int ny = y + dy[k];

			if (nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
			if (island[nx][ny] == island[a][b]) continue;
			if (island[nx][ny] != 0 && island[nx][ny] != island[a][b]) return dari[x][y];			
			if (!visit[nx][ny]) {
				q.push(make_pair(nx, ny));
				visit[nx][ny] = true;
				dari[nx][ny] = dari[x][y] + 1;
			}
		}
	}
	
	return bridge;
}
void island_numbering(int a, int p, int q)
{
	queue<pair<int, int>> qq;
	qq.push(make_pair(p, q));
	while (!qq.empty()) {
		int x = qq.front().first;
		int y = qq.front().second;
		qq.pop();
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (nx >= 0 && nx < n && ny >= 0 && ny < n && !visit[nx][ny] && mp[nx][ny]) {
				visit[nx][ny] = true;
				qq.push(make_pair(nx, ny));
				island[nx][ny] = a;
			}
		}
	}
}
int main()
{
	freopen("input.txt", "r", stdin);
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			cin >> mp[i][j];

	int num = 1;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (mp[i][j] && !visit[i][j]) {
				visit[i][j] = true;
				island[i][j] = num;
				island_numbering(num++,i,j);
			}
		}
	}

	int leng = 10001;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (island[i][j]) {
				int tmp = make_bridge(i,j);
				if (leng > tmp)
					leng = tmp;
			}
		}
	}
	cout << leng << endl;
}