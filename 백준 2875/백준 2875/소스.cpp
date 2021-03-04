#pragma warning(disable : 4996)
#include <iostream>
using namespace std;

int main()
{
	int n, m, k;
	cin >> n >> m >> k;
	int cnt = 0;
	while (n + m >= k + 3) {
		n -= 2; m--;
		if (n >= 0 && m >= 0)
			cnt++;
	}
	cout << cnt << endl;
}