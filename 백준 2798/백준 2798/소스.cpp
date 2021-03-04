#pragma warning(disable : 4996)
#include <iostream>
using namespace std;

int mx = 0;
int card[100];
bool check[100];
void solve(int n, int m, int cnt, int ix)
{
	if (cnt == 3) {
		int sum = 0;
		for (int k = 0; k < n; k++) {
			if (check[k])
				sum += card[k];
		}
		if (sum <= m) {
			if (mx < sum)
				mx = sum;
		}
		return;
	}
	for (int k = ix; k < n; k++) {
		if (check[k]) continue;
		check[k] = true;
		solve(n, m, cnt + 1, k + 1);
		check[k] = false;
	}
}
int main()
{
	freopen("input.txt", "r", stdin);
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n,m;
	cin >> n >> m;
	for (int i = 0; i < n; i++)
		cin >> card[i];
	solve(n, m, 0, 0);
	cout << mx << endl;
}