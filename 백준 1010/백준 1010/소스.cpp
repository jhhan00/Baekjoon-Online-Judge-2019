#pragma warning(disable : 4996)
#include <iostream>
using namespace std;

int main()
{
	freopen("input.txt", "r", stdin); 
	cin.tie(NULL);
	cout.tie(NULL);
	int t, i, j, n ,m; 
	int pcal[30][30];
	pcal[0][0] = 1;
	for (i = 0; i <= 29; i++) {
		for (j = 0; j <= i; j++) {
			if (j == 0 || j == i)
				pcal[i][j] = 1;
			else
				pcal[i][j] = pcal[i - 1][j - 1] + pcal[i - 1][j];
		}
	}
	cin >> t;
	for (i = 0; i < t; i++) {
		cin >> n >> m;
		cout << pcal[m][n] << "\n";
	}
}
