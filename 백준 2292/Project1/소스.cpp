#include <iostream>
using namespace std;

int main()
{
	int n, a1, d1, cnt;
	cin >> n;
	if (n == 1) {
		cout << n << endl;
		return 0;
	}
	a1 = 2; d1 = 6; cnt = 1;
	while (a1 <= n)
	{
		a1 += d1;
		d1 += 6;
		cnt++;
	}
	cout << cnt << endl;
}