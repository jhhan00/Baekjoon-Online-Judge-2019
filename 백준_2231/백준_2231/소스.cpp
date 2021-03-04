#pragma warning(disable : 4996)
#include <iostream>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		int sum = 0;
		sum += i;
		int j = i;
		while (j > 0) {
			int tmp = j % 10;
			sum += tmp;
			j /= 10;
		}
		if (sum == n) {
			cout << i;
			return 0;
		}
	}
	cout << 0;
}