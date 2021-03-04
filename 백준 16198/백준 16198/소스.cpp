#pragma warning(disable : 4996)
#include <iostream>
#include <vector>
using namespace std;

int solve(vector<int> &v)
{
	int ans = 0;
	int ww = v.size();
	if (ww == 2)
		return 0;
	for (int i = 1; i < ww - 1; i++) {
		int tmp = v[i - 1] * v[i + 1];
		vector<int> y(v);
		y.erase(y.begin() + i);
		tmp += solve(y);
		if (ans < tmp)
			ans = tmp;
	}
	return ans;
}

int main()
{
	freopen("input.txt", "r", stdin);
	int n,i,num;
	vector<int> vv;
	cin >> n;
	for (i = 0; i < n; i++) {
		cin >> num;
		vv.push_back(num);
	}
	cout << solve(vv) << "\n";
}