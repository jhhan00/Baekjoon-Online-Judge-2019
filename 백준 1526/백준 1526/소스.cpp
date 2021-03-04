#pragma warning(disable : 4996)
#include <iostream>
using namespace std;

bool fourseven(int k)
{
	while (k > 0)
	{
		if (k % 10 != 4 && k % 10 != 7) return false;
		else k /= 10;
	}
	return true;
}
int main()
{
	ios_base::sync_with_stdio(false);
	int n;
	cin >> n;
	int m = n;
	if (fourseven(m)) {
		cout << m << endl;
		return 0;
	}
	for (int i = n - 1; i >= 0; i--) {
		if (fourseven(i)) {
			cout << i << endl;
			break;
		}
	}
}