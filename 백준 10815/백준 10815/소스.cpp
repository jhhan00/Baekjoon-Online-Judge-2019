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
	int n, a, m, b;
	vector<long long> v1;
	vector<long long> v2;
	cin >> n;
	while (n--) {
		cin >> a;
		v1.push_back(a);
	}
	sort(v1.begin(), v1.end());
	cin >> m;
	while (m--) {
		cin >> b;
		v2.push_back(b);
	}
	vector<int> check;
	for (int i = 0; i < v2.size(); i++) {
		int left = 0;
		int right = v1.size() - 1;
		int mid;
		bool c = false;
		while (left <= right) {
			mid = (left + right) / 2;
			if (v1[mid] == v2[i]) {
				c = true;
				break;
			}
			else if (v2[i] > v1[mid])
				left = mid + 1;
			else if (v2[i] < v1[mid])
				right = mid - 1;
		}
		if(c) check.push_back(1);
		else check.push_back(0);
	}
	for (int i = 0; i < v2.size(); i++)
		cout << check[i] << ' ';
	cout << '\n';
}