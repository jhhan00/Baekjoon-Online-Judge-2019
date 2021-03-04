#pragma warning(disable : 4996)
#include <iostream>
#define EE 15
#define SS 28
#define MM 19
using namespace std;

int main()
{
	freopen("input.txt", "r", stdin);
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int e, s, m;
	cin >> e >> s >> m;
	if (e == EE) e = 0;
	if (s == SS) s = 0;
	if (m == MM) m = 0;
	for (int i = 1; i <= EE * SS*MM; i++) {
		if (i%EE != e) continue;
		if (i%SS != s) continue;
		if (i%MM != m) continue;
		cout << i << '\n';
		break;
	}
}