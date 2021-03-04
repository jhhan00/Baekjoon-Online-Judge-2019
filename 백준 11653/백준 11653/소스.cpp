#pragma warning(disable : 4996)
#include <iostream>
using namespace std;

bool check(int a)
{
	if (a < 2)
		return true;
	for (int i = 2; i*i <= a; i++) {
		if (a%i == 0)
			return true;
	}
	return false;
}

int main() 
{
	int n, i, j;
	bool ck;
	cin >> n;
	j = n;
	for (i = 2; i*i <= j; i++) {
		ck = check(i);
		if (!ck) {
			while (n%i == 0) {
				n = n / i;
				cout << i << "\n";
			}
		}
	}
	if (n > 1)
		cout << n << "\n";
}