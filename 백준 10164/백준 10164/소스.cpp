#pragma warning(disable : 4996)
#include <iostream>
using namespace std;

int mp[16][16];
int comb[16][16];
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n, m, k;
	cin >> n >> m >> k;
	if (k == 0) {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= m; j++) {
				if (i == 1 || j == 1)
					comb[i][j] = 1;
				else
					comb[i][j] = comb[i - 1][j] + comb[i][j - 1];
			}
		}
		cout << comb[n][m] << "\n";
		return 0;
	}
	int x = 1,a,b;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			mp[i][j] = x++;
			if (mp[i][j] == k) {
				a = i;
				b = j;
			}
		}
	}
	for (int i = 1; i <= a; i++) {
		for (int j = 1; j <= b; j++) {
			if (i == 1 || j == 1)
				comb[i][j] = 1;
			else
				comb[i][j] = comb[i - 1][j] + comb[i][j - 1];
		}
	}
	for (int i = a; i <= n; i++) {
		for (int j = b; j <= m; j++) {
			if (i == a || j == b)
				comb[i][j] = comb[a][b];
			else
				comb[i][j] = comb[i - 1][j] + comb[i][j - 1];
		}
	}
	cout << comb[n][m] << endl;
}