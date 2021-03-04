#pragma warning(disable : 4996)
#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
#define MAX 101
using namespace std;

int r, c, k;
int v[MAX][MAX];
int numcount[MAX];
int main()
{
	freopen("input.txt", "r", stdin);
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> r >> c >> k;
	for (int i = 1; i <= 3; i++) {
		for (int j = 1; j <= 3; j++) {
			cin >> v[i][j];
		}
	}
	
	int cnt = 0;
	int row = 3, col = 3;
	while (cnt <= 100) {
		if (v[r][c] == k) break;
		
		vector<pair<int, int>> tmp;
		vector<int> sz;
		if (col > row) { // C연산
			for (int j = 1; j <= col; j++) {
				memset(numcount, 0, sizeof(numcount));
				vector<pair<int, int>> tmp;
				for (int i = 1; i <= row; i++)
					numcount[v[i][j]]++;

				for (int i = 1; i < MAX; i++) {
					if (numcount[i])
						tmp.push_back(make_pair(numcount[i], i));
				}
				sort(tmp.begin(), tmp.end());
				for (int i = 1; i < MAX; i++)
					v[i][j] = 0;
				int idx = 1;
				for (int i = 0; i < tmp.size(); i++) {
					v[idx++][j] = tmp[i].second;
					v[idx++][j] = tmp[i].first;
				}
				idx--;
				sz.push_back(idx);
			}
			sort(sz.begin(), sz.end());
			row = sz.back();
		}
		else { // R연산
			for (int i = 1; i <= row; i++) {
				memset(numcount, 0, sizeof(numcount));
				vector<pair<int, int>> tmp;
				for (int j = 1; j <= col; j++)
					numcount[v[i][j]]++;
				
				for (int j = 1; j < MAX; j++) {
					if (numcount[j]) {
						tmp.push_back(make_pair(numcount[j], j));
					}
				}
				sort(tmp.begin(), tmp.end());
				for (int j = 1; j < MAX; j++)
					v[i][j] = 0;
				int idx = 1;
				for (int j = 0; j < tmp.size(); j++) {
					v[i][idx++] = tmp[j].second;
					v[i][idx++] = tmp[j].first;
				}
				idx--;
				sz.push_back(idx);
			}
			sort(sz.begin(), sz.end());
			col = sz.back();
		}
		cnt++;
	}
	/*
	for (int i = 1; i <= row; i++) {
		for (int j = 1; j <= col; j++)
			cout << v[i][j] << " ";
		cout << endl;
	}cout << endl;*/
	if (cnt > 100)
		cout << -1 << endl;
	else
		cout << cnt << endl;
}