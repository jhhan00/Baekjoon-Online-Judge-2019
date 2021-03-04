#pragma warning(disable : 4996)
#include <iostream>
#include <vector>
using namespace std;

vector<long long> c;
void merge(vector<long long> &a, vector<long long> &b)
{
	int l, r, x, y;
	l = r = 0;
	x = a.size(); y = b.size();
	while (l != x && r != y) {
		if (a[l] > b[r])
			c.push_back(b[r++]);
		else
			c.push_back(a[l++]);
	}
	if (l == x) {
		for (int i = r; i < y; i++)
			c.push_back(b[i]);
	}
	else {
		for (int i = l; i < x; i++)
			c.push_back(a[i]);
	}
	for (int i = 0; i < c.size(); i++)
		cout << c[i] << ' ';
}
int main()
{
	freopen("input.txt", "r", stdin);
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	int n, m, l;
	cin >> n >> m;
	vector<long long> a; vector<long long> b;
	for (int i = 0; i < n; i++) {
		cin >> l;
		a.push_back(l);
	}
	for (int i = 0; i < m; i++) {
		cin >> l;
		b.push_back(l);
	}
	merge(a, b);
}