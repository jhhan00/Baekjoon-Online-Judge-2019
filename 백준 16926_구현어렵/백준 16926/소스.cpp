#pragma warning(disable : 4996)
#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
	freopen("input.txt", "r", stdin);
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	int n, m, l;
	cin >> n >> m >> l;
	int a[300][300];
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			cin >> a[i][j];
	int q = min(n, m) / 2;
	for (int c = 0; c < q; c++) {
		for (int b = 0; b < l; b++) {
			int s = a[c][c];
			for (int i = c + 1; i < m - c; i++) {
				a[c][i - 1] = a[c][i];
			}
			for (int i = c + 1; i < n - c; i++) {
				a[i - 1][m - 1 - c] = a[i][m - 1 - c];
			}
			for (int i = m - 1 - c; i > c; i--) {
				a[n - 1 - c][i] = a[n - 1 - c][i - 1];
			}
			for (int i = n - 1 - c; i > c; i--) {
				a[i][c] = a[i - 1][c];
			}
			a[c + 1][c] = s;
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++)
			cout << a[i][j] << ' ';
		cout << '\n';
	}
}