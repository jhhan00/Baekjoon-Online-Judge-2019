#pragma warning(disable : 4996)
#include <iostream>
#include <cstring>
#include <string>
#include <queue>
using namespace std;

int check[10001];
bool isPrime(int x)
{
	for (int i = 2; i*i <= x; i++) {
		if (x%i == 0)
			return false;
	}
	return true;
}
int bfs(int a, int b)
{
	check[a] = 1;
	queue<int> q;
	q.push(a);
	while (!q.empty()) {
		int x = q.front(); q.pop();
		if (x == b) return check[x];
		for (int i = 3; i >= 0; i--) {
			for (int j = 0; j < 10; j++) {
				string st = to_string(x);
				st[i] = j + '0';
				int st1 = stoi(st);
				if (st1 < 1000) continue;
				if (isPrime(st1) && check[st1] == 0) {
					check[st1] = check[x] + 1;
					q.push(st1);
				}
			}
		}
	}
	return -1;
}
int main()
{
	freopen("input.txt", "r", stdin);
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	int n;
	cin >> n;
	while (n--) {
		int a, b, ans;
		cin >> a >> b;
		memset(check, 0, sizeof(check));
		if (a == b) {
			cout << 0 << endl;
			continue;
		}
		ans=bfs(a, b);
		if (ans < 0)
			cout << "Impossible" << endl;
		else
			cout << ans - 1 << endl;
	}
}