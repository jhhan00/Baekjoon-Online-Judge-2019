#pragma warning(disable : 4996)
#include <iostream>
using namespace std;

bool pr[101];
int main()
{
	freopen("input.txt", "r", stdin);
	cin.tie(NULL);
	int t;
	cin >> t;
	while (t--) {
		int n, i, j, cnt=0;
		cin >> n;
		for (i = 1; i <= n; i++)
			pr[i] = true;
		for (i = 2; i <= n; i++) {
			for (j = 1; i*j <= n; j++) {
				if (pr[i*j] == true)
					pr[i*j] = false;
				else
					pr[i*j] = true;
			}
		}
		for (i = 1; i <= n; i++)
			if (pr[i] == true)
				cnt++;
		cout << cnt << "\n";
	}
}