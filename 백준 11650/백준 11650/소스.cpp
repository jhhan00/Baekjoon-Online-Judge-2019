#pragma warning(disable : 4996)
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
struct paper {
	int x;
	int y;
};
bool comp(const paper &a, const paper &b)
{
	if (a.x == b.x)
		return a.y < b.y;
	else
		return a.x < b.x;
}
int main()
{
	freopen("input.txt", "r", stdin);
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n;
	cin >> n;
	vector<paper> v(n);
	for (int i = 0; i < n; i++)
		cin >> v[i].x >> v[i].y;
	sort(v.begin(), v.end(), comp);
	for (int i = 0; i < n; i++)
		cout << v[i].x << ' ' << v[i].y << '\n';
}