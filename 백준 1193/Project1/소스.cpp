#include <iostream>
using namespace std;

int main()
{
	int n, ss, cnt, bg, bm, tmp;
	cin >> n;
	ss = 1;
	cnt = 1;
	while (ss < n) {
		ss += cnt;
		cnt++;
	}
	cnt--;
	ss -= cnt;
	tmp = n - ss;
	if (cnt % 2 == 0)
	{
		bm = cnt-tmp;
		bg = 1+tmp;
		if (bm == 0)
			bm = 1;
	}
	else
	{
		bm = 1+tmp;
		bg = cnt-tmp;
		if (bg == 0)
			bg = 1;
	}
	cout << bg << "/" << bm << endl;
	return 0;
}
