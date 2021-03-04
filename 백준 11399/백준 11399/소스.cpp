#pragma warning(disable : 4996)
#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
	freopen("input.txt", "r", stdin);
	int nn;
	cin >> nn;
	int *atm = new int[nn];
	int *wait = new int[nn];
	for (int i = 0; i < nn; i++)
		wait[i] = 0;
	int ting = 0;
	for (int i = 0; i < nn; i++)
		cin >> atm[i];

	sort(atm, atm + nn);
	for (int i = 0; i < nn; i++) {
		for (int j = 0; j <= i; j++) {
			wait[i] += atm[j];
		}
		ting += wait[i];
	}
	cout << ting << endl;
}