#pragma warning(disable : 4996)
#include <iostream>
#include <vector>
using namespace std;

int n, m;
int mp[51][51];
bool ch[51][51];
int ans = 0;
vector<int> hx; vector<int> hy;
void mini_distance(vector<int> &a, vector<int> &b)
{ // 집과 치킨집의 위치로 최소거리 측정
	int sum = 0;
	for (int i = 0; i < hx.size(); i++) {
		int mini = 0;
		for (int j = 0; j < a.size(); j++) {
			int dx = hx[i] - a[j];
			int dy = hy[i] - b[j];
			if (dx < 0) dx = -dx;
			if (dy < 0) dy = -dy;
			if (mini == 0 || mini > dx + dy)
				mini = dx + dy;
		}
		sum += mini;
	}
	if (ans == 0 || ans > sum)
		ans = sum;
}
void chicken(int a, int cnt) // 치킨집 선정
{
	if (cnt == m) { // 치킨집을 모두 선정했을 때
		vector<int> vx; vector<int> vy;
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				if (ch[i][j]) { // 그 때의 치킨집 위치 저장
					vx.push_back(i);
					vy.push_back(j);
				}
			}
		}
		mini_distance(vx, vy);
		return;
	}
	//조합을 응용함
	for (int i = a; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (mp[i][j] == 2 && ch[i][j] == false) {
				ch[i][j] = true;
				chicken(i, cnt+1);
				ch[i][j] = false;
			}
		}
	}
}
int main()
{
	freopen("input.txt", "r", stdin);
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> mp[i][j];
			if (mp[i][j] == 1) { // 집일 경우 위치 따로 저장
				hx.push_back(i);
				hy.push_back(j);
			}
		}
	}
	chicken(1, 0);
	cout << ans << '\n';
}