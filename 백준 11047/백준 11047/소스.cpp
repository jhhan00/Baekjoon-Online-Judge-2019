#pragma warning(disable : 4996)
#include <iostream>
using namespace std;

int main()
{
	freopen("input.txt", "r", stdin);
	int n, k, i;
	int coincnt = 0;
	cin >> n >> k;
	int *coin = new int[n];
	for (i = 0; i < n; i++)
		cin >> coin[i];
	i = n - 1;
	for (int a = i; a >= 0; a--) {
		if (k == 0) break;
		while (k >= coin[a]) {
			k -= coin[a];
			coincnt++;
		}
	}
	cout << coincnt << endl;
}