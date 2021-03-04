#pragma warning(disable : 4996)
#include <iostream>
using namespace std;

int miro[1000][1000];
int candy[1000][1000];

int main()
{
	freopen("input.txt", "r", stdin);
	int n, m, i, j;
	cin >> n >> m;
	for (i = 0; i < n; i++)
		for (j = 0; j < m; j++)
			cin >> miro[i][j];

	candy[0][0] = miro[0][0];
	for (i = 1; i < m; i++)
		candy[0][i] = miro[0][i] + candy[0][i - 1];
	for (i = 1; i < n; i++)
		candy[i][0] = miro[i][0] + candy[i - 1][0];
	
	for (i = 1; i < n; i++) {
		for (j = 1; j < m; j++) {
			if (candy[i - 1][j] + miro[i][j] > candy[i][j - 1] + miro[i][j])
				candy[i][j] = candy[i - 1][j] + miro[i][j];
			else
				candy[i][j] = candy[i][j - 1] + miro[i][j];
		}
	}
	for (i = 0; i < n; i++) {
		for (j = 0; j < m; j++)
			cout << candy[i][j] << " ";
		cout << "\n";
	}
	cout << candy[n - 1][m - 1] << endl;
}