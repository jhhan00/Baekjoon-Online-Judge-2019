#pragma warning(disable : 4996)
#include <iostream>
#include <algorithm>
#define NMB 1000000001
using namespace std;

int n;
int maxi = -NMB;
int mini = NMB;
int a[12];

void go(int ix, int rs, int pl, int mn, int ml, int dv)
{
	if (ix==n) {
		mini = min(mini, rs);
		maxi = max(maxi, rs);
	}
	if (pl > 0)
		go(ix + 1, rs + a[ix], pl - 1, mn, ml, dv);
	if (mn > 0)
		go(ix + 1, rs - a[ix], pl, mn - 1, ml, dv);
	if (ml > 0)
		go(ix + 1, rs * a[ix], pl, mn, ml - 1, dv);
	if (dv > 0)
		go(ix + 1, rs / a[ix], pl, mn, ml, dv - 1);
}

int main()
{
	int i;
	int op[4];
	freopen("input.txt", "r", stdin);
	cin >> n;
	for (i = 0; i < n; i++)
		cin >> a[i];
	for (i = 0; i < 4; i++)
		cin >> op[i];
	go(1, a[0], op[0], op[1], op[2], op[3]);
	cout << maxi << "\n" << mini << "\n";
}