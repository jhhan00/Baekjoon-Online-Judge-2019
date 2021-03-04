//���� 9328 : ���� ����
#pragma warning(disable : 4996)
#include <iostream>
#include <cstring>
#include <string>
#include <queue>
using namespace std;

char mp[101][101];
bool visited[101][101];
bool key[26];
int bfs(int h, int w)
{
	int dx[] = { 0,0,-1,1 };
	int dy[] = { -1,1,0,0 };
	int cnt = 0;
	queue<pair<int, int>> q;
	q.push(make_pair(0, 0)); // (0,0)���� ����!
	visited[0][0] = true;
	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (nx<0 || nx > h + 1 || ny<0 || ny > w + 1) continue;
			if (mp[nx][ny] == '*') continue; // ���� ���
			if (visited[nx][ny]) continue; // �̹� �湮�� ���

			if (mp[nx][ny] == '.') { // �� ����
				q.push(make_pair(nx, ny));
				visited[nx][ny] = true;
			}
			else if (mp[nx][ny] == '$') { // ã��, ��������
				mp[nx][ny] = '.'; // ã���� ���߿� �ߺ��� ���� �����ؼ� '.'���� �ʱ�ȭ
				visited[nx][ny] = true;
				q.push(make_pair(nx, ny));
				cnt++;
			}
			else if (mp[nx][ny] >= 'A' && mp[nx][ny] <= 'Z') { // ���� ���� ���������� �� ����
				if (key[mp[nx][ny]-'A']) { // ���� �´� ���谡 ���� ���� ����
					q.push(make_pair(nx, ny));
					visited[nx][ny] = true;
				}
			}
			else if (mp[nx][ny] >= 'a' && mp[nx][ny] <= 'z') { // ���� ã��
				if (key[mp[nx][ny] - 'a'] == false) { // ���踦 ó�� ã���� �� �ʱ�ȭ
					key[mp[nx][ny] - 'a'] = true;
					memset(visited, false, sizeof(visited));
				}
				q.push(make_pair(nx, ny));
				visited[nx][ny] = true;
			}
		}
	}
	return cnt;
}
int main()
{
	freopen("input.txt", "r", stdin);
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	int n;
	cin >> n;
	while (n--) {
		int h, w;
		cin >> h >> w;
		memset(mp, '.', sizeof(mp)); // ��� ĭ�� '.'���� �ʱ�ȭ�ؼ� (0,0) ~ (h+1,w+1)���� ������
		memset(key, false, sizeof(key));
		memset(visited, false, sizeof(visited));
		for (int i = 1; i <= h; i++) {
			for (int j = 1; j <= w; j++)
				cin >> mp[i][j];
		}
		string s;
		cin >> s;
		if (s != "0") { // 0�� �ƴϸ� �� �ڸ����� Ȯ���ؼ� key�迭�� ����
			for (int i = 0; i < s.size(); i++)
				key[s[i] - 'a'] = true;
		}
		cout << bfs(h, w) << endl;
	}
}