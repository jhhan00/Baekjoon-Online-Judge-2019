#pragma warning(disable : 4996)
#include <iostream>
using namespace std;

int main()
{
	freopen("input.txt", "r", stdin);
	int n, i;
	int max = 0;
	cin >> n;
	int *wine = new int[n];
	int *drink = new int[n];
	for (i = 0; i < n; i++) {
		cin >> wine[i];
		drink[i] = 0;
	}
	for (i = 0; i < n; i++) {
		if (i == 0)
			drink[i] += wine[i];
		else if (i == 1)
			drink[i] = wine[i] + drink[i - 1];
		else if (i == 2) {
			if (wine[i] + wine[i - 1] > wine[i] + wine[i - 2])
				drink[i] = wine[i] + wine[i - 1];
			else
				drink[i] = wine[i] + wine[i - 2];
		}
		else {
			if (wine[i] + drink[i - 2] > wine[i] + wine[i - 1] + drink[i - 3])
				drink[i] = wine[i] + drink[i - 2];
			else
				drink[i] = wine[i] + wine[i - 1] + drink[i - 3];
		}
		if (i >= 1 && drink[i] < drink[i - 1])
			drink[i] = drink[i - 1];
	}
	for (i = 0; i < n; i++)
		cout << drink[i] << " ";
	cout << "\n" << drink[n-1] << endl;
	delete[] wine;
	delete[] drink;
}