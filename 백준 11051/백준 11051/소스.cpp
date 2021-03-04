#pragma warning(disable : 4996)
#include <iostream>
#define DIV 10007
using namespace std;

int cb[1001][1001];

int main()
{
	int n, k, i, j;
	cb[0][0] = 1;
	for (i = 1; i < 1001; i++) {
		for (j = 0; j <= i; j++) {
			if (j == 0 || i == j)
				cb[i][j] = 1;
			else
				cb[i][j] = cb[i - 1][j - 1] + cb[i - 1][j];
			cb[i][j] %= DIV;
		}
	}
	cin >> n >> k;
	cout << cb[n][k] << "\n";
}