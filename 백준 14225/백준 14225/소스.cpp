#pragma warning(disable : 4996)
#include <iostream>
using namespace std;

int n;
int a[21];
bool b[20*100000+10];

void solve(int idx, int sum)
{
	if (idx == n) {
		b[sum] = true;
		return;
	}
	solve(idx + 1, sum + a[idx]);
	solve(idx + 1, sum);
}

int main()
{
	int i, j;
	freopen("input.txt", "r", stdin);
	cin >> n;
	for (i = 0; i < n; i++)
		cin >> a[i];
	solve(0, 0);
	for (i = 0;; i++) {
		if (b[i] == false) {
			cout << i << "\n";
			break;
		}
	}
}