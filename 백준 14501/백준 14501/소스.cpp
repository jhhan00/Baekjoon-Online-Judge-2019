#pragma warning(disable : 4996)
#include <iostream>
#include <algorithm>
using namespace std;

int T[16], P[16], d[16];
int t, ans=0;

void go(int day, int money)  // void함수를 이용할 경우
{
	if (day > t + 1)
		return;
	if (day == t + 1) {
		if (ans < money)
			ans = money;
		return;
	}

	go(day + 1, money); // 상담을 하지 않는 경우
	go(day + T[day], money + P[day]); // 상담을 하는 경우
}
/*
int go(int day)  // int함수를 이용할 경우
{
	if (day > t + 1)
		return -99999;
	if (day == t + 1)
		return 0;
	if (d[day] != -1)
		return d[day];
	int k1 = go(day + 1);
	int k2 = P[day] + go(day + T[day]);
	d[day] = max(k1, k2);
	return d[day];
}
*/
int main()
{
	freopen("input.txt", "r", stdin);
	cin.tie(NULL);
	int i;
	cin >> t;
	for (i = 1; i <= t; i++) {
		cin >> T[i] >> P[i];
		d[i] = -1;
	}
	go(1, 0);
	//cout << go(1) << "\n";
	cout << ans << "\n";
}