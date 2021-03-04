#pragma warning(disable : 4996)
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

typedef struct Meeting {
	int begin;
	int end;
}MT;
bool comp(MT a, MT b)
{
	if (a.end == b.end)
		return a.begin < b.begin;
	else
		return a.end < b.end;
}
int main()
{
	freopen("input.txt", "r", stdin);
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	vector<MT> v(n);
	for (int i = 0; i < n; i++)
		cin >> v[i].begin >> v[i].end;
	sort(v.begin(), v.end(), comp);

	int ans = 0, now = 0;
	for (int i = 0; i < n; i++) {
		if (now <= v[i].begin) {
			now = v[i].end;
			ans++;
			cout << now << "\n";
		}
	}
	cout << ans << '\n';
}