#pragma warning(disable : 4996)
#include <iostream>
#include <string>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

int map[25][25];
int countTown[25][25];
int N;
int townNum = 0;
int dx[4] = {0,0,-1,1};
int dy[4] = {-1,1,0,0};
vector<int> v;

void BFStown(int x, int y, int num)
{
	int cnt = 0;
	queue<int> qx; queue<int> qy;
	qx.push(x); qy.push(y);
	while (!qx.empty() && !qy.empty()) {
		int nowX = qx.front(); qx.pop();
		int nowY = qy.front(); qy.pop();
		
		for (int i = 0; i < 4; i++) {
			int newX = nowX + dx[i];
			int newY = nowY + dy[i];

			if (newX >= 0 && newX < N && newY >= 0 && newY < N && map[newX][newY] == 1 && countTown[newX][newY] == 0) {
				qx.push(newX); qy.push(newY);
				countTown[newX][newY] = num;
				cnt++;
			}
		}
	}
	v.push_back(cnt);
}

int main()
{
	freopen("input.txt", "r", stdin);	
	string st;
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> st;
		for (int j = 0; j < N; j++) {
			map[i][j] = st[j]-'0';
		}
	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (map[i][j] == 1 && countTown[i][j] == 0) {
				townNum++;
				BFStown(i,j,townNum);
			}
		}
	}
	
	sort(v.begin(), v.end());
	cout << v.size() << "\n";
	for (int i = 0; i < v.size(); i++)
		cout << v[i] << "\n";
}