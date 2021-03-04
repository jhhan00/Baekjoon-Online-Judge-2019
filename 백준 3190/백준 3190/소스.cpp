#pragma warning(disable : 4996)
#include <iostream>
using namespace std;

int mp[101][101];
int apple[101][101];
int dx[] = { 0,1,0,-1 };
int dy[] = { 1,0,-1,0 };
int main()
{
	freopen("input.txt", "r", stdin);
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n, m, l;
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		apple[a][b] = 1;
	}
	cin >> l;
	int num[100];
	char ld[100];
	for (int i = 0; i < l; i++) {
		int a; char b;
		cin >> a >> b;
		num[i] = a; ld[i] = b;
	}
	int x = 1, y = 1; // 현재 위치
	int bdlen = 1;
	int j = 0;
	int ans = 0;
	int k = 0; // 방향 값
	while (1) {
		ans++;
		x = x + dx[k];
		y = y + dy[k];
		if (x<1 || x>n || y<1 || y>n) break;
		if (apple[x][y] == 1) {
			bdlen++;
			apple[x][y] = 0;
		}
		if (mp[x][y] != 0 && ans - mp[x][y] <= bdlen) break;		
		mp[x][y] = ans;
		if (ans == num[j]) {
			if (ld[j] == 'D')
				k = (k + 1) % 4;
			else
				k = (k - 1 + 4) % 4;
			j++;
		}
	}
	cout << ans << '\n';
}