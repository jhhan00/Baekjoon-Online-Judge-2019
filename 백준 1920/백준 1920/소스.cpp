#pragma warning(disable : 4996)
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	freopen("input.txt", "r", stdin);
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n,m,x;
	cin >> n;
	vector<int> v;
	for (int i = 0; i < n; i++) {
		cin >> x;
		v.push_back(x);
	}
	sort(v.begin(), v.end());
	int sz = v.size();
	cin >> m;
	while (m--) {
		cin >> x;
		if (x < v[0] || x > v[sz - 1]) {
			cout << 0 << "\n";
			continue;
		}
		int left = 0, right = sz - 1, mid;
		bool find = false;
		while (left <= right) {
			mid = (left + right) / 2;
			if (v[mid] == x) {
				find = true;
				break;
			}
			else if (v[mid] > x) {
				right = mid - 1;
			}
			else if (v[mid] < x) {
				left = mid + 1;
			}
		}
		if (find) cout << 1 << "\n";
		else cout << 0 << "\n";
	}
}