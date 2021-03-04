#pragma warning(disable : 4996)
#include <iostream>
#include <vector>
#include <queue>
#define MAX 100001
using namespace std;

vector<int> vv[MAX];
bool visited[MAX];
int parent[MAX];
void bfs(int a);
int main()
{
	freopen("input.txt", "r", stdin);
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n,i;
	cin >> n;
	
	for (i = 0; i < n - 1; i++) {
		int a, b;
		cin >> a >> b;
		vv[a].push_back(b);
		vv[b].push_back(a);
	}
	bfs(1);
	for (i = 2; i <= n; i++)
		cout << parent[i] << '\n';
}
void bfs(int a)
{
	visited[a] = true;
	parent[a] = 0;
	queue<int> q;
	q.push(a);
	while (!q.empty()) {
		int x = q.front();
		q.pop();
		for (int y = 0; y < vv[x].size(); y++) {
			if (visited[vv[x][y]] == false) {
				visited[vv[x][y]] = true;
				parent[vv[x][y]] = x;
				q.push(vv[x][y]);
			}
		}
	}
}