#pragma warning(disable : 4996)
#include <iostream>
#include <cstring>
using namespace std;

int dx[] = { 0,0,-1,1 };
int dy[] = { -1,1,0,0 };
int mp[100][100];
bool visit[100][100];
void dfs(int a, int b, int n, int xx)
{
	visit[a][b] = true;
	for (int i = 0; i < 4; i++) {
		int nx = a + dx[i];
		int ny = b + dy[i];
		if (nx >= 0 && nx < n && ny >= 0 && ny<n && visit[nx][ny] == false && mp[nx][ny]>xx) {
			dfs(nx, ny, n, xx);
		}
	}
}
int gogo(int n, int xx) 
{
	memset(visit, false, sizeof(visit));
	int ans = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (mp[i][j] > xx && visit[i][j] == false) {
				ans++;
				dfs(i, j, n, xx);
			}
		}
	}
	return ans;
}
int main()
{
	freopen("input.txt", "r", stdin);
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	int mx = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> mp[i][j];
			if (mx < mp[i][j])
				mx = mp[i][j];
		}
	}
	int ans = 0;
	for (int i = 1; i <= mx; i++) {
		int qq = gogo(n, i);
		if (ans < qq)
			ans = qq;
	}
	cout << ans << endl;
}