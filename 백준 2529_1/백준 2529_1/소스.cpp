#pragma warning(disable : 4996)
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

char neq[9];
bool visit[10];
vector<string> ans;

bool look(char op, char x, char y)
{
	if (op == '<') {
		if (x > y) return false;
	}
	else {
		if (x < y) return false;
	}
	return true;
}

void find(int a, string aa, int id)
{
	if (id == a + 1) {
		//cout << aa << "\n";
		ans.push_back(aa);
		return;
	}
	for (int i = 0; i < 10; i++) {
		if (visit[i]) continue;		
		if (id == 0 || look(neq[id - 1], aa[id - 1], i + '0')) {
			visit[i] = true;
			find(a, aa + to_string(i), id + 1);
			visit[i] = false;
		}		
	}
}

int main()
{
	freopen("input.txt", "r", stdin);
	ios_base::sync_with_stdio(false);
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> neq[i];
	find(n, "", 0);
	sort(ans.begin(), ans.end());
	cout << ans[ans.size() - 1] << "\n" << ans[0] << "\n";
}