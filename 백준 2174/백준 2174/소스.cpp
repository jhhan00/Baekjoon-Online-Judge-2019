#pragma warning(disable : 4996)
#include <iostream>
#include <vector>
using namespace std;

int dx[] = { -1,0,1,0 };
int dy[] = { 0,1,0,-1 }; // N:0, E:1, S:2, W:3 일때
int mp[101][101];
vector<pair<pair<int, int>, char>> vv;
int direction(char c)
{
	if (c == 'N') return 0;
	else if (c == 'E') return 1;
	else if (c == 'S') return 2;
	else return 3;
}
char turn_lr(char hh, char cc)
{
	if (hh == 'L') { // turn left
		if (cc == 'N') return 'W';
		else if (cc == 'E') return 'N';
		else if (cc == 'S') return 'E';
		else return 'S';
	}
	else { // turn right
		if (cc == 'N') return 'E';
		else if (cc == 'E') return 'S';
		else if (cc == 'S') return 'W';
		else return 'N';
	}
}
bool go(int s, int k, char h, int b, int a) // s:번호, k:횟수, h:명령종류
{
	int ox = vv[s - 1].first.first;
	int oy = vv[s - 1].first.second;
	char cc = vv[s - 1].second;
	if (h == 'F') { // 직진인 경우
		int d = direction(cc);
		int nx = ox, ny = oy;
		for (int i = 0; i < k; i++) {
			nx += dx[d];
			ny += dy[d];
			if (nx<1 || nx>b || ny<1 || ny>a) {
				cout << "Robot " << s << " crashes into the wall" << endl;
				return false;
			}
			if (mp[nx][ny]) {
				cout << "Robot " << s << " crashes into robot " << mp[nx][ny] << endl;
				return false;
			}
		}
		mp[nx][ny] = s;
		mp[ox][oy] = 0;
		vv[s - 1].first.first = nx;
		vv[s - 1].first.second = ny;
	}
	else { // 좌/우회전인 경우
		for (int i = 0; i < k; i++) {
			cc = turn_lr(h, cc);
		}
		vv[s - 1].second = cc;
	}
	return true;
}
int main()
{
	freopen("input.txt", "r", stdin);
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	int a, b, n, m;
	cin >> a >> b >> n >> m;
	for (int i = 1; i <= n; i++) {
		int x, y; char c;
		cin >> y >> x >> c;
		mp[b-x+1][y] = i;
		vv.push_back({ {b-x+1,y},c });
	}
	
	while (m--) {
		int s, k; char h;
		cin >> s >> h >> k;
		if (!go(s, k, h, b, a))
			return 0;
	}
	cout << "OK" << endl;
}