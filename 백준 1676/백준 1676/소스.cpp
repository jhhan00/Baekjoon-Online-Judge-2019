#pragma warning(disable : 4996)
#include <iostream>
using namespace std;

int main()
{
	int t, ans = 0;
	cin >> t;
	for (int i = 1; i <= t; i++) {
		if (i % 5 == 0)
			ans++;
		if (i % 25 == 0)
			ans++;
		if (i % 125 == 0)
			ans++;
	}
	cout << ans << "\n";
}