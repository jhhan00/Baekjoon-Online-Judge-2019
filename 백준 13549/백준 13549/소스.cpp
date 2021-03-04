#pragma warning(disable : 4996)
#include <iostream>
#include <queue>
#define MAX 100001
#define INFI 999999999
using namespace std;

int visit[MAX];
int bfs(int a, int b)
{
	int dd[3];
	queue<int> q;
	q.push(a);
	visit[a] = 0;
	if (a >= b)
		return a-b;
	while (!q.empty()) {
		int c = q.front();
		q.pop();
		if (c == b)
			return visit[b];
		dd[0] = c - 1;
		dd[1] = c + 1;
		dd[2] = c * 2;
		if (dd[0] >= 0 && visit[dd[0]] > visit[c] + 1) {
			q.push(dd[0]);
			visit[dd[0]] = visit[c] + 1;
		}
		if (dd[1] < MAX && (visit[dd[1]] > visit[c] + 1)) {
			q.push(dd[1]);
			visit[dd[1]] = visit[c] + 1;			
		}
		if (dd[2] < MAX && (visit[dd[2]] > visit[c])) {
			q.push(dd[2]);
			visit[dd[2]] = visit[c];
		}
	}
}

int main()
{
	int n, k;
	cin >> n >> k;
	for (int i = 0; i < MAX; i++)
		visit[i] = INFI;
	cout << bfs(n, k) << "\n";
}