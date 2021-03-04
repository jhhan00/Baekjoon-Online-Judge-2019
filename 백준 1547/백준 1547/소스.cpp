#pragma warning(disable : 4996)
#include <iostream>
#include <algorithm>
using namespace std;

bool ball[4];
int main()
{
	freopen("input.txt", "r", stdin);
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int m;
	cin >> m;
	ball[1] = true;
	while (m--) {
		int x, y;
		cin >> x >> y;
		swap(ball[x], ball[y]);
	}
	int ans = 0;
	for (int i = 1; i < 4; i++) {
		if (ball[i])
			ans = i;
	}
	cout << ans;
}