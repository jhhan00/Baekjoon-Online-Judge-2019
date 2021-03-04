#pragma warning(disable : 4996)
#include <iostream>
using namespace std;

int ten[10];
int main()
{
	int n, a;
	bool six = false;
	cin >> n;
	if (n == 0) {
		cout << 1 << "\n";
		return 0;
	}
	int num = 0;
	while (n > 0) {
		a = n % 10;
		if (a == 6)
			ten[9]++;
		else
			ten[a]++;
		n /= 10;
	}
	ten[9] = (ten[9] + 1) / 2;
	for (a = 0; a < 10; a++)
		if (num < ten[a])
			num = ten[a];
	cout << num << "\n";
}