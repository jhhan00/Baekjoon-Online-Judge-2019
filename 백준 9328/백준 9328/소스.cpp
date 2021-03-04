//백준 9328 : 열쇠 문제
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
	q.push(make_pair(0, 0)); // (0,0)부터 시작!
	visited[0][0] = true;
	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (nx<0 || nx > h + 1 || ny<0 || ny > w + 1) continue;
			if (mp[nx][ny] == '*') continue; // 벽인 경우
			if (visited[nx][ny]) continue; // 이미 방문한 경우

			if (mp[nx][ny] == '.') { // 빈 공간
				q.push(make_pair(nx, ny));
				visited[nx][ny] = true;
			}
			else if (mp[nx][ny] == '$') { // 찾음, 개수증가
				mp[nx][ny] = '.'; // 찾으면 나중에 중복될 것을 방지해서 '.'으로 초기화
				visited[nx][ny] = true;
				q.push(make_pair(nx, ny));
				cnt++;
			}
			else if (mp[nx][ny] >= 'A' && mp[nx][ny] <= 'Z') { // 문에 도착 열쇠있으면 문 해제
				if (key[mp[nx][ny]-'A']) { // 문에 맞는 열쇠가 있을 때만 가능
					q.push(make_pair(nx, ny));
					visited[nx][ny] = true;
				}
			}
			else if (mp[nx][ny] >= 'a' && mp[nx][ny] <= 'z') { // 열쇠 찾음
				if (key[mp[nx][ny] - 'a'] == false) { // 열쇠를 처음 찾았을 때 초기화
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
		memset(mp, '.', sizeof(mp)); // 모든 칸을 '.'으로 초기화해서 (0,0) ~ (h+1,w+1)까지 쓰게함
		memset(key, false, sizeof(key));
		memset(visited, false, sizeof(visited));
		for (int i = 1; i <= h; i++) {
			for (int j = 1; j <= w; j++)
				cin >> mp[i][j];
		}
		string s;
		cin >> s;
		if (s != "0") { // 0이 아니면 각 자리마다 확인해서 key배열에 저장
			for (int i = 0; i < s.size(); i++)
				key[s[i] - 'a'] = true;
		}
		cout << bfs(h, w) << endl;
	}
}