#pragma warning(disable : 4996)
#include <iostream>
using namespace std;

int main()
{
	cout << sizeof(long long) << endl;
	int n;
	cin >> n;
	int sq[100001];
	sq[0] = 0;
	for (int i = 1; i <= n; i++) {
		sq[i] = i;
		for (int j = 1; j*j <= i; j++){
			if (sq[i] > sq[i - j * j] + 1)
				sq[i] = sq[i - j * j] + 1;
		}
	}
	cout << sq[n] << endl;
}