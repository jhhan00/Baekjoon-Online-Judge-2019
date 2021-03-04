#pragma warning(disable : 4996)
#include <iostream>
#include <algorithm>
using namespace std;

bool vs[14];
int lt[14];
int n;

void comb(int x, int y)
{
	int i;
	if (y == 6) {
		for (i = 0; i < n; i++)
			if (vs[i])
				cout << lt[i] << " ";
		cout << "\n";
		return;
	}
	for (i = x; i < n; i++) {
		if (vs[i]) continue;
		vs[i] = true;
		comb(i + 1, y + 1);
		vs[i] = false;
	}
}

int main()
{
	freopen("input.txt", "r", stdin);
	cin.tie(NULL);
	while (1) {
		cin >> n;
		if (n == 0)
			break;
		for (int i = 0; i < n; i++) {
			cin >> lt[i];
			vs[i] = false;
		}
		sort(lt, lt + n);
		comb(0, 0);
		cout << "\n";
	}
}