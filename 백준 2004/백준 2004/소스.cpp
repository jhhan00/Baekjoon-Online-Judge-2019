#pragma warning(disable : 4996)
#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
	int n, m, k, comb, num, i, two, fiv;
	cin >> n >> m;
	k = n - m;
	two = 0; fiv = 0;
	if (m == 0 || k == 0)
		cout << 0 << "\n";
	else {
		comb = 1; num = 1;
		for (i = k; i <= n; i++) {
			comb *= i;
			comb /= num++;
			while (comb % 2 == 0) {
				comb /= 2;
				two++;
			}
			while (comb % 5 == 0) {
				comb /= 5;
				fiv++;
			}
			cout << i << " " << two << " " << fiv << "\n";
		}
	}
	cout << endl;
	cout << two << " " << fiv << "\n";
	cout << min(two, fiv) << endl;
}