#pragma warning(disable : 4996)
#include <iostream>
#include <queue>
using namespace std;
/* 
int n;
int change[1000001];

int bfs()
{
	int go;
	int math[3];
	queue<int> q;
	q.push(1);
	while (!q.empty()) {
		go = q.front(); q.pop();
		if (go == n) break;
		math[0] = go * 3;
		math[1] = go * 2;
		math[2] = go + 1;
		if (math[0] <= n && change[math[0]] == 0) {
			q.push(math[0]);
			change[math[0]] = change[go] + 1;
		}
		if (math[1] <= n && change[math[1]] == 0) {
			q.push(math[1]);
			change[math[1]] = change[go] + 1;
		}
		if (math[2] <= n && change[math[2]] == 0) {
			q.push(math[2]);
			change[math[2]] = change[go] + 1;
		}
	}
	return change[go];
}

int main()
{
	cin >> n;
	int answer = bfs();
	cout << answer << endl;
}*/
int change[1000001];

int main()
{
	int t, i;
	cin >> t;
	change[1]=0;
	change[2]=1;
	change[3]=1;

	if (t <= 3)
		cout << change[t] << endl;
	else {
		for (i = 4; i <= t; i++) {
			change[i] = change[i - 1] + 1;
			if (i % 2 == 0 && change[i] > change[i / 2] + 1)
				change[i] = change[i / 2] + 1;
			if (i % 3 == 0 && change[i] > change[i / 3] + 1)
				change[i] = change[i / 3] + 1;
		}
		cout << change[t] << endl;
	}
}