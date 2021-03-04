#pragma warning(disable : 4996)
#include <iostream>
using namespace std;

int main()
{
	freopen("input.txt", "r", stdin);
	int n, i;
	cin >> n;
	int *num = new int[n];
	int *hap = new int[n];
	for (i = 0; i < n; i++)
		cin >> num[i];
	
	hap[0] = num[0];
	int max = hap[0];
	for (i = 1; i < n; i++) {
		if (hap[i - 1] + num[i] > num[i])
			hap[i] = hap[i - 1] + num[i];
		else
			hap[i] = num[i];

		if (hap[i] > max)
			max = hap[i];
	}
	cout << max << endl;

	delete[] num;
	delete[] hap;
}