#include <iostream>
#include <queue>
using namespace std;
#define MAX 1001

int graph[MAX][MAX];
int visit[MAX];

void initgraph()
{
	for (int i = 0; i < MAX; i++)
		for (int j = 0; j < MAX; j++)
			graph[i][j] = 0;
}

void initvisit()
{
	for (int i = 0; i < MAX; i++)
		visit[i] = 0;
}

void DFS(int start, int node)
{
	visit[start] = 1;
	cout << start << " ";

	for (int i = 1; i <= node; i++)	
		if (graph[start][i] == 1 && visit[i] == 0)
			DFS(i, node);
}

void BFS(int start, int node)
{
	initvisit();
	visit[start] = 1;

	queue<int> q;
	q.push(start);

	while (!q.empty())
	{
		int a = q.front();
		cout << a << " ";
		q.pop();
		for (int b = 1; b <= node; b++)
		{
			if (graph[a][b] == 1 && visit[b] == 0)
			{
				visit[b] = 1;
				q.push(b);
			}
		}
	}
	cout << endl;
}

int main()
{
	int n, m, v;
	cin >> n >> m >> v;
	initgraph();
	for (int i = 0; i < m; i++)
	{
		int x, y;
		cin >> x >> y;
		graph[x][y] = 1; graph[y][x] = 1;
	}

	DFS(v, n); cout << "\n";
	BFS(v, n);
}