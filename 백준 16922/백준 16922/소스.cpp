#pragma warning(disable : 4996)
#include <iostream>
using namespace std;

bool check[1001];
int main()
{
	int n;
	cin >> n;
	int one, fv, tn, ff, val;
	// ���� ����Լ� ������ �ʰ� ������ ������ �ľ��� �� ����ص� �ȴ�
	// ����Լ� ������ �ð��ʰ� ��...
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