#pragma warning(disable : 4996)
#include <iostream>
#include <deque>
using namespace std;

void print(deque<int> &dq)
{
	deque<int> dd(dq);
	while (!dd.empty()) {
		cout << dd.front() << ' ';
		dd.pop_front();
	}cout << endl;
}
int main()
{
	freopen("input.txt", "r", stdin);
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n, m;
	cin >> n >> m;	
	deque<int> dq;
	for (int i = 1; i <= n; i++)
		dq.push_back(i);
	int ans = 0;
	for (int i = 0; i < m; i++) {
		int now,ix;
		int sz = dq.size();
		cin >> now;
		if (dq.front() == now) {
			dq.pop_front(); print(dq);
			continue;
		}
		for (int j = 0; j < sz; j++) {
			if (dq[j] == now)
				ix = j;
		}
		int lf = ix;
		int rg = sz - ix;
		if (lf > rg) {
			for (int j = 0; j < rg; j++) {
				int k = dq.back();
				dq.pop_back();
				dq.push_front(k);
				ans++;
			}
		}
		else {
			for (int j = 0; j < lf; j++) {
				int k = dq.front();
				dq.pop_front();
				dq.push_back(k);
				ans++;
			}
		}
		dq.pop_front();
		print(dq);
	}
	cout << ans << endl;
}