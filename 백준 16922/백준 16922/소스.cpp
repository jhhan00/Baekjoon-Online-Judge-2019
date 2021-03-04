#pragma warning(disable : 4996)
#include <iostream>
using namespace std;

bool check[1001];
int main()
{
	int n;
	cin >> n;
	int one, fv, tn, ff, val;
	// 굳이 재귀함수 돌리지 않고 각각의 개수를 파악한 뒤 계산해도 된다
	// 재귀함수 돌리면 시간초과 남...
	for (one = 0; one <= n; one++) {
		for (fv = 0; fv <= n - one; fv++) {
			for (tn = 0; tn <= n - one - fv; tn++) {
				ff = n - one - fv - tn;
				val = one + 5 * fv + 10 * tn + 50 * ff;
				check[val] = true;
			}
		}
	}
	int ans = 0;
	for (int i = 0; i < 1001; i++)
		if (check[i])
			ans++;
	cout << ans << '\n';
}