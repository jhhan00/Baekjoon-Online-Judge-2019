#pragma warning(disable : 4996)
#include <iostream>
#include <cstring>
#include <queue>
#define DIS 100000
using namespace std;

int visit[DIS+1];
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	int a, b, n, m;
	cin >> a >> b >> n >> m;
	memset(visit, -1, sizeof(visit));
	queue<int> q;
	q.push(n);
	visit[n] = 0;
	while (!q.empty())
	{
		int x = q.front(); q.pop();
		if (x == m) {
			cout << visit[x] << '\n';
			return 0;
		}
		if (x - 1 >= 0 && visit[x - 1] == -1) {
			visit[x - 1] = visit[x] + 1;
			q.push(x - 1);
		}
		if (x + 1 <= DIS && visit[x + 1] == -1) {
			visit[x + 1] = visit[x] + 1;
			q.push(x + 1);
		}
		if (x - a >= 0 && visit[x - a] == -1) {
			visit[x - a] = visit[x] + 1;
			q.push(x - a);
		}
		if (x + a <= DIS && visit[x + a] == -1) {
			visit[x + a] = visit[x] + 1;
			q.push(x + a);
		}
		if (x - b >= 0 && visit[x - b] == -1) {
			visit[x - b] = visit[x] + 1;
			q.push(x - b);
		}
		if (x + b <= DIS && visit[x + b] == -1) {
			visit[x + b] = visit[x] + 1;
			q.push(x + b);
		}
		if (x*a <= DIS && visit[x*a] == -1) {
			visit[x*a] = visit[x] + 1;
			q.push(x*a);
		}
		if (x*b <= DIS && visit[x*b] == -1) {
			visit[x*b] = visit[x] + 1;
			q.push(x*b);
		}
	}
}