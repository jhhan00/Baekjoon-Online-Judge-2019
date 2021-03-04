#pragma warning(disable : 4996)
#include <iostream>
#include <vector>
#include <set>
using namespace std;

int n, m, d;
int mp[16][16];
int solve(int a1, int a2, int a3)
{
	int cp[16][16];
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			cp[i][j] = mp[i][j];

	vector<pair<int, int>> va;
	va.push_back(make_pair(n + 1, a1));
	va.push_back(make_pair(n + 1, a2));
	va.push_back(make_pair(n + 1, a3));

	int sum = 0;
	for (int s = 0; s < n; s++) {
		set<pair<int, int>> ss;
		for (int k = 0; k < va.size(); k++) {
			int x = va[k].first;
			int y = va[k].second;
			int svx=n+1, svy=m+1, svd=d+1;
			for (int i = 1; i <= n; i++) {
				for (int j = 1; j <= m; j++) {
					if (cp[i][j] == 0) continue;
					int dx = x - i;
					int dy = y - j;
					if (dy < 0) dy = -dy;
					if (dx + dy <= d) {
						if (dx + dy < svd) {
							svx = i; svy = j; svd = dx + dy;
						}
						else if (dx + dy == svd && j < svy) {
							svx = i; svy = j;
						}
					}
				}
			}
			if (svx == n + 1 && svy == m + 1) continue;
			ss.insert({ svx,svy });
		}
		//cout << ss.size() << " ";
		sum += ss.size();
		for (auto aa = ss.begin(); aa != ss.end(); aa++)
			cp[aa->first][aa->second] = 0;

		for (int i = n; i > 1; i--) {
			for (int j = 1; j <= m; j++)
				cp[i][j] = cp[i - 1][j];
		}
		for (int j = 1; j <= m; j++)
			cp[1][j] = 0;
	}//cout << endl;
	return sum;
}
int main()
{
	freopen("input.txt", "r", stdin);
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> n >> m >> d;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			cin >> mp[i][j];
	
	int ans = 0;
	for (int a = 1; a <= m; a++) {
		for (int b = a + 1; b <= m; b++) {
			for (int c = b + 1; c <= m; c++) {
				int rt = solve(a, b, c);
				if (ans < rt)
					ans = rt;
			}
		}
	}
	cout << ans << endl;
}