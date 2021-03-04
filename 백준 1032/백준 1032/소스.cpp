#pragma warning(disable : 4996)
#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main()
{
	freopen("input.txt", "r", stdin);
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	int n;
	cin >> n;
	vector<string> vst;
	for (int i = 0; i < n; i++) {
		string s;
		cin >> s;
		vst.push_back(s);
	}
	string ans;
	ans = vst[0];
	for (int i = 1; i < n; i++) {
		for (int j = 0; j < vst[i].size(); j++) {
			if (ans[j] != vst[i][j])
				ans[j] = '?';
		}
	}
	cout << ans << endl;
}