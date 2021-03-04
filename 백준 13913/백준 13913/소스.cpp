#pragma warning(disable : 4996)
#include <iostream>
#include <queue>
#define MAX 100001
using namespace std;

int visit[MAX];
int from[MAX];

int find(int a, int b)
{
	queue<int> qq;
	qq.push(a);
	while (!qq.empty()) {
		int c = qq.front();
		qq.pop();
		if (c == b)
			return visit[c];
		if (c - 1 >= 0 && visit[c - 1] == 0 && from[c-1] != -1) {
			visit[c - 1] = visit[c] + 1;
			from[c - 1] = c;
			qq.push(c - 1);
		}
		if (c + 1 < MAX && visit[c + 1] == 0 && from[c+1] != -1) {
			visit[c + 1] = visit[c] + 1;
			from[c + 1] = c;
			qq.push(c + 1);
		}
		if (c * 2 < MAX && visit[c * 2] == 0 && from[c*2] != -1) {
			visit[c * 2] = visit[c] + 1;
			from[c * 2] = c;
			qq.push(c * 2);
		}
	}
}

void print(int z)
{
	if (from[z] != -1)
		print(from[z]);
	cout << z << " ";
}

int main()
{
	int n, k;
	cin >> n >> k;
	visit[n] = 0;
	from[n] = -1;
	cout << find(n, k) << "\n";
	print(k);
}