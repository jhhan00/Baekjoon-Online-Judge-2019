#pragma warning(disable : 4996)
#include <iostream>
#include <queue>
using namespace std;

int ev[1000001];
int main()
{
	freopen("input.txt", "r", stdin);
	int f, s, g, u, d;
	cin >> f >> s >> g >> u >> d;
	for (int i = 1; i <= f; i++)
		ev[i] = -1;
	ev[s] = 0;
	queue<int> qf;
	qf.push(s);
	while (!qf.empty()) {
		int x = qf.front();
		qf.pop();
		if (x == g)
			break;
		if (x + u <= f && ev[x + u] == -1) {
			ev[x + u] = ev[x] + 1;
			qf.push(x + u);
		}
		if (x - d >= 0 && ev[x - d] == -1) {
			ev[x - d] = ev[x] + 1;
			qf.push(x - d);
		}
	}
	if (ev[g] == -1)
		cout << "use the stairs\n";
	else
		cout << ev[g] << '\n';
}