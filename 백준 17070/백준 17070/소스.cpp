#pragma warning(disable : 4996)
#include <iostream>
#include <queue>
using namespace std;

int home[17][17];
int ans[17][17];
void bfs(int n)
{
	queue<pair<int, int>> q1;
	queue<pair<int, int>> q2;
	q1.push(make_pair(1, 1));
	q2.push(make_pair(1, 2));
	while (!q1.empty()) {
		int x1 = q1.front().first;
		int y1 = q1.front().second; q1.pop();
		int x2 = q2.front().first;
		int y2 = q2.front().second; q2.pop();
		if (x2 == n && y2 == n) continue;
		if (x1 == x2) // ������ ��
		{
			if (x2 + 1 <= n && y2 + 1 <= n) { // ���ο��� �밢��
				if (!home[x2][y2 + 1] && !home[x2 + 1][y2] && !home[x2 + 1][y2 + 1]) {
					q1.push(make_pair(x2, y2));
					q2.push(make_pair(x2 + 1, y2 + 1));
					ans[x2 + 1][y2 + 1]++;
				}
			}
			if (y2 + 1 <= n && !home[x2][y2 + 1]) { // ���ο��� ����
				q1.push(make_pair(x2, y2));
				q2.push(make_pair(x2, y2 + 1));
				ans[x2][y2 + 1]++;
			}
		}
		else if (y1 == y2) //������ ��
		{
			if (x2 + 1 <= n && y2 + 1 <= n) { //���ο��� �밢��
				if (!home[x2][y2 + 1] && !home[x2 + 1][y2] && !home[x2 + 1][y2 + 1]) {
					q1.push(make_pair(x2, y2));
					q2.push(make_pair(x2 + 1, y2 + 1));
					ans[x2 + 1][y2 + 1]++;
				}
			}
			if (x2 + 1 <= n && !home[x2+1][y2]) { // ���ο��� ����
				q1.push(make_pair(x2, y2));
				q2.push(make_pair(x2 + 1, y2));
				ans[x2 + 1][y2]++;
			}
		}
		else // �밢���� ��
		{
			if (x2 + 1 <= n && y2 + 1 <= n) { // �밢������ �밢��
				if (!home[x2][y2 + 1] && !home[x2 + 1][y2] && !home[x2 + 1][y2 + 1]) {
					q1.push(make_pair(x2, y2));
					q2.push(make_pair(x2 + 1, y2 + 1));
					ans[x2 + 1][y2 + 1]++;
				}
			}
			if (y2 + 1 <= n && !home[x2][y2 + 1]) { // �밢������ ����
				q1.push(make_pair(x2, y2));
				q2.push(make_pair(x2, y2 + 1));
				ans[x2][y2 + 1]++;
			}
			if (x2 + 1 <= n && !home[x2 + 1][y2]) { // �밢������ ����
				q1.push(make_pair(x2, y2));
				q2.push(make_pair(x2 + 1, y2));
				ans[x2 + 1][y2]++;
			}
		}
	}
}
int main()
{
	freopen("input.txt", "r", stdin);
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			cin >> home[i][j];
	bfs(n);
	
	cout << ans[n][n] << endl;
}