#pragma warning(disable : 4996)
#include <iostream>
using namespace std;

int min = 9999999;
int ss[21][21];
bool team[21];
void solve(int n, int ix, int cnt)
{
	if (cnt == n / 2)
	{
		int sum1 = 0, sum2 = 0;
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				if (team[i] && team[j])
					sum1 += ss[i][j];
				if (!team[i] && !team[j])
					sum2 += ss[i][j];
			}
		}
		int tmp = sum1 - sum2;
		if (tmp < 0) tmp = -tmp;
		if (min > tmp) min = tmp;
		return;
	}
	for (int k = ix; k <= n; k++) {
		if (team[k]) continue;
		team[k] = true;
		solve(n, k + 1, cnt + 1);
		team[k] = false;
	}
}
int main()
{
	freopen("input.txt", "r", stdin);
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			cin >> ss[i][j];
	solve(n, 1, 0);
	cout << min << endl;
}