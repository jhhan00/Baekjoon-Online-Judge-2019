#include <iostream>
#include <queue>
using namespace std;
#define MAX 100001

int visited[MAX];

void FindBFS(int a, int b)
{
	int ans[3];	
	queue<int> q;
	q.push(a);
	visited[a] = 1;

	while (!q.empty())
	{
		int pos = q.front();
		q.pop();
		if (pos == b) {
			cout <<  visited[pos] - 1 << endl;
			break;
		}
		ans[0] = pos + 1;
		ans[1] = pos - 1;
		ans[2] = pos * 2;
		if (ans[0] >= 0 && ans[0] < MAX && visited[ans[0]] == 0) {
			q.push(ans[0]);
			visited[ans[0]] = visited[pos] + 1;
		}
		if (ans[1] >= 0 && ans[1] < MAX && visited[ans[1]] == 0) {
			q.push(ans[1]);
			visited[ans[1]] = visited[pos] + 1;
		}
		if (ans[2] >= 0 && ans[2] < MAX && visited[ans[2]] == 0) {
			q.push(ans[2]);
			visited[ans[2]] = visited[pos] + 1;
		}
	}
}

int main()
{
	int n, k;
	cin >> n >> k;
	
	FindBFS(n, k);
}