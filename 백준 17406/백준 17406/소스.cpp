#pragma warning(disable : 4996)
#include <iostream>
#include <vector>
using namespace std;

int N,M,K;
int a[51][51];
vector<pair<pair<int, int>, int>> cm;
bool check[6];
int ans = 50001;
int solve(vector<int> bb)
{
	int cp[51][51];
	for (int i = 1; i <= N; i++)
		for (int j = 1; j <= M; j++)
			cp[i][j] = a[i][j];

	for (int s = 0; s < bb.size(); s++) {
		int x = cm[bb[s]].first.first;
		int y = cm[bb[s]].first.second;
		int z = cm[bb[s]].second;
		int startx = x - z, starty = y - z;
		int endx = x + z, endy = y + z;
		for (int k = 0; k < z; k++) {
			int tmp = cp[startx][starty];
			for (int i = startx; i < endx; i++) {
				cp[i][starty] = cp[i + 1][starty];
			}
			for (int i = starty; i < endy; i++) {
				cp[endx][i] = cp[endx][i + 1];
			}
			for (int i = endx; i > startx; i--) {
				cp[i][endy] = cp[i - 1][endy];
			}
			for (int i = endy; i > starty; i--) {
				cp[startx][i] = cp[startx][i - 1];
			}
			cp[startx][starty + 1] = tmp;
			startx++; starty++; endx--; endy--;
		}
	}
	int mn = 50001;
	for (int i = 1; i <= N; i++) {
		int sum = 0;
		for (int j = 1; j <= M; j++) {
			sum += cp[i][j];
		}
		if (mn > sum)
			mn = sum;
	}
	return mn;
}
void go(vector<int> aa)
{
	if (aa.size() == K) {
		int rt = solve(aa);
		if (ans > rt)
			ans = rt;
		return;
	}
	for (int i = 0; i < cm.size(); i++) {
		if (check[i]) continue;
		check[i] = true;
		aa.push_back(i);
		go(aa);
		aa.pop_back();
		check[i] = false;
	}
}
int main()
{
	freopen("input.txt", "r", stdin);
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> N >> M >> K;
	for (int i = 1; i <= N; i++)
		for (int j = 1; j <= M; j++)
			cin >> a[i][j];
	for (int q = 0; q < K; q++) {
		int aa, bb, cc;
		cin >> aa >> bb >> cc;
		cm.push_back({ {aa,bb},cc });
	}
	vector<int> vv(0);
	go(vv);
	cout << ans << endl;
}