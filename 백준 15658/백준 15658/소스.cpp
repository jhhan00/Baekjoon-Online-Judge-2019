#pragma warning(disable : 4996)
#include <iostream>
#define CON 1000000001
using namespace std;

int n;
int aa[13];
int mx = -CON;
int mn = CON;

void go(int id, int ans, int plus, int minus, int mul, int divi)
{
	if (id == n) {
		if (mx < ans) mx = ans;
		if (mn > ans) mn = ans;
		return;
	}
	if (plus > 0)
		go(id + 1, ans + aa[id], plus - 1, minus, mul, divi);
	if (minus > 0)
		go(id + 1, ans - aa[id], plus, minus - 1, mul, divi);
	if (mul > 0)
		go(id + 1, ans * aa[id], plus, minus, mul - 1, divi);
	if (divi > 0)
		go(id + 1, ans / aa[id], plus, minus, mul, divi - 1);
}

int main()
{
	int i;
	freopen("input.txt", "r", stdin);
	ios_base::sync_with_stdio(false);
	cin >> n;
	for (i = 0; i < n; i++)
		cin >> aa[i];
	int ps, ms, ml, dv;
	cin >> ps >> ms >> ml >> dv;
	go(1, aa[0], ps, ms, ml, dv);
	cout << mx << "\n" << mn << "\n";
}