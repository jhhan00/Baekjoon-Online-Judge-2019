#pragma warning(disable : 4996)
#include <iostream>
#include <string>
#include <stack>
using namespace std;

int main()
{
	freopen("input.txt", "r", stdin);
	cin.tie(NULL);
	int t, i, k;
	string ans;
	stack<int> sk;
	cin >> t;
	int now = 0;
	for (i = 0; i < t; i++) {
		cin >> k;
		if (k > now) {
			while (k > now) {
				sk.push(++now);
				ans += '+';
			}
			sk.pop();
			ans += '-';
		}
		else {
			if (k == sk.top()) {
				sk.pop();
				ans += '-';
			}
			else {
				cout << "NO" << "\n";
				return 0;
			}
		}
	}
	for (i = 0; i < ans.size(); i++)
		cout << ans[i] << "\n";
}
