#pragma warning(disable : 4996)
#include <iostream>
#include <string>
#include <queue>
#include <tuple>
using namespace std;

string s;
bool vs[1501][1501];
void bfs(int n, int a, int b)
{
	int sz = s.size() - 1;
	queue<tuple<int, int, int>> q;
	q.push(make_tuple(a, b, 0));
	vs[a][b] = true;
	int mx = 0;
	while (!q.empty())
	{
		int l, r, cnt;
		tie(l, r, cnt) = q.front(); q.pop();
		if (mx < cnt)
			mx = cnt;
		if (l + r < 3 * n) {
			// 3*n과 같거나 크면 약을 다 먹은 후 이기 때문에 더이상 진행 안해도 됨
			char c; // 먹어야 할 약을 정해주는 변수
			if (cnt % 3 == 0) c = 'B';
			else if (cnt % 3 == 1) c = 'L';
			else c = 'D';

			if (s[l] == c && !vs[l + 1][r]) {
				vs[l + 1][r] = true;
				q.push(make_tuple(l + 1, r, cnt + 1));
			}
			if (s[sz - r] == c && !vs[l][r + 1]) {
				vs[l][r + 1] = true;
				q.push(make_tuple(l, r + 1, cnt + 1));
			}
		}
	}
	cout << mx << endl;
}
int main()
{
	freopen("input.txt", "r", stdin);
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	cin >> s;
	bfs(n, 0, 0);
}