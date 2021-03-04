#pragma warning(disable : 4996)
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int n;
char bdh[9];
bool vs[10];
vector<string> ans;

bool check(string str)
{
	for (int i = 0; i < n; i++) {
		if (bdh[i] == '<') {
			if (str[i] > str[i + 1]) 
				return false;			
		}
		else {
			if (str[i] < str[i + 1]) 
				return false;			
		}
	}
	return true;
}

void go(int id, string st)
{
	if (id == n + 1) {
		if (check(st))
			ans.push_back(st);
		return;
	}
	for (int i = 0; i < 10; i++) {
		if (vs[i]) continue;
		vs[i] = true;
		go(id + 1, st + to_string(i));
		vs[i] = false;
	}
}

int main()
{
	freopen("input.txt", "r", stdin);
	ios_base::sync_with_stdio(false);
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> bdh[i];
	string s = "";
	go(0, s);
	sort(ans.begin(), ans.end());
	int qq = ans.size();
	cout << ans[qq-1] << "\n" << ans[0] << "\n";
}