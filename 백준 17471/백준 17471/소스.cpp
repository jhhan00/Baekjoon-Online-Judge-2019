#pragma warning(disable : 4996)
#include <iostream>
#include <cstring>
#include <vector>
#include <queue>
#define MAX 11
using namespace std;

int n, ans = INT32_MAX;
int person[MAX];
bool mp[MAX][MAX];
bool check[MAX];
bool visit[MAX];
bool bfs(vector<int> vv, bool bl) // true�� �����ؾ� �ùٸ� ������
{
	memset(visit, false, sizeof(visit));
	queue<int> q;
	q.push(vv[0]);
	visit[vv[0]] = true;
	int count = 1;
	while (!q.empty()) {
		int x = q.front(); q.pop();
		for (int i = 1; i <= n; i++) {
			if (mp[x][i] && check[i] == bl && !visit[i]) {
				visit[i] = true;
				count++;
				q.push(i);
			}
		}
	}

	if (count == vv.size()) return true;
	return false;
}
bool find()
{
	vector<int> one, two;
	for (int i = 1; i <= n; i++) {
		if (check[i]) one.push_back(i);
		else two.push_back(i);
	}

	// �����̶� 0�̸� �� ������ ����� �ȵ��� ����
	if (one.size() == 0 || two.size() == 0) return false;

	if (bfs(one, true) == false) return false;

	if (bfs(two, false) == false) return false;

	return true;
}
void combination(int ix, int cnt) // ������ �̿��ؼ� �� ����
{
	if (cnt >= 1) { // �� ������ �Ϸ��
		if (find()) { // find()�� ���� ���� �������� Ȯ��
			vector<int> v1, v2;
			for (int i = 1; i <= n; i++) {
				if (check[i]) v1.push_back(i);
				else v2.push_back(i);
			}
			int s1 = 0, s2 = 0, s = 0;
			for (int i = 0; i < v1.size(); i++)
				s1 += person[v1[i]];
			for (int i = 0; i < v2.size(); i++)
				s2 += person[v2[i]];
			s = s1 - s2;
			if (s < 0) s = -s;
			if (ans > s)
				ans = s;
		}
	}

	for (int i = ix; i <= n; i++) {
		if (check[i]) continue;
		check[i] = true;
		combination(ix + 1, cnt + 1);
		check[i] = false;
	}
}
int main()
{
	freopen("input.txt", "r", stdin);
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> person[i];
	
	for (int i = 1; i <= n; i++) {
		int a;
		cin >> a;
		for (int j = 0; j < a; j++) {
			int b;
			cin >> b;
			mp[i][b] = true;
		}
	}

	combination(1, 0);
	if (ans == INT32_MAX)
		cout << -1 << endl;
	else
		cout << ans << endl;
}