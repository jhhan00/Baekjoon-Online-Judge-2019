#pragma warning(disable : 4996)
#include <iostream>
#include <string>
#include <queue>
#include <set> // 처음 써보는 STL
#define MAX 1000000001
using namespace std;

void bfs(long long s, long long t);
int main()
{
	long long s, t;
	cin >> s >> t;
	if (s == t) {
		cout << 0 << endl;
		return 0;
	}
	bfs(s, t);
}
void bfs(long long s, long long t)
{
	queue<long long> qs; queue<string> qt;
	qs.push(s); qt.push("");
	set<long long> check;
	check.insert(s);
	while (!qs.empty() && !qt.empty()) {
		long long x = qs.front(); qs.pop();
		string st = qt.front(); qt.pop();
		if (x == t) {
			cout << st << endl;
			return;
		}
		if (x*x < MAX && check.count(x*x)==0) {
			qs.push(x*x);
			qt.push(st + '*');
			check.insert(x*x);
		}
		if (x + x < MAX && check.count(x+x) == 0) {
			qs.push(x + x);
			qt.push(st + '+');
			check.insert(x+x);
		}
		if (x - x >= 0 && check.count(x-x) == 0) {
			qs.push(x - x);
			qt.push(st + '-');
			check.insert(x-x);
		}
		if (x != 0 && x / x >= 0 && check.count(x/x) == 0) {
			qs.push(x / x);
			qt.push(st + '/');
			check.insert(x/x);
		}
	}
	cout << -1 << endl;
	return;
}