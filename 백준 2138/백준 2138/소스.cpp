#pragma warning(disable : 4996)
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main()
{
	freopen("input.txt", "r", stdin);
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n;
	cin >> n;
	string a, b;
	cin >> a >> b;
	string c = a, d = a; // c�� 0��°���� �ٲٱ�, d�� 1��°���� �ٲٱ�
	int ans1 = 1;
	int ans2 = 0;
	c[0] = 97 - c[0]; c[1] = 97 - c[1]; // c�� 0���� ���� ó�� ����
	for (int i = 1; i < n; i++) { // ����� c��d ��� ����
		if (i == n - 1) {
			if (c[i - 1] != b[i - 1]) {
				c[i - 1] = 97 - c[i - 1];
				c[i] = 97 - c[i];
				ans1++;
			}
		}
		else {
			if (c[i - 1] != b[i - 1]) {
				c[i - 1] = 97 - c[i - 1];
				c[i] = 97 - c[i];
				c[i + 1] = 97 - c[i + 1];
				ans1++;
			}
		}		
	}
	for (int i = 1; i < n; i++) { // ����� c��d ��� ����
		if (i == n - 1) {
			if (d[i - 1] != b[i - 1]) {
				d[i - 1] = 97 - d[i - 1];
				d[i] = 97 - d[i];
				ans2++;
			}
		}
		else {
			if (d[i - 1] != b[i - 1]) {
				d[i - 1] = 97 - d[i - 1];
				d[i] = 97 - d[i];
				d[i + 1] = 97 - d[i + 1];
				ans2++;
			}
		}		
	}
	cout << c << '\n' << d << '\n';
	if (c == b && d == b)
		cout << min(ans1, ans2) << '\n';
	else if (c == b)
		cout << ans1 << '\n';
	else if (d == b)
		cout << ans2 << '\n';
	else
		cout << -1 << '\n';
}