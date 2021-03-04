#pragma warning(disable : 4996)
#include <iostream>
using namespace std;

int pn[1001];

int primenumber(int a)
{
	if (a < 2)
		return 1;
	for (int i = 2; i*i <= a; i++)
		if (a%i == 0)
			return 1;	
	return 0;
}

int main()
{
	freopen("input.txt", "r", stdin);
	cin.tie(NULL);
	int t, i, j, ans;
	cin >> t;
	for (i = 0; i < t; i++) 
		cin >> pn[i];
	
	ans = 0;
	for (i = 0; i < t; i++) {
		j = primenumber(pn[i]);
		if (!j)
			ans++;
	}
	cout << ans << "\n";
}