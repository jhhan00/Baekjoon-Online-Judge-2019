#pragma warning(disable : 4996)
#include <iostream>
#include <vector>
using namespace std;

int n;
int sum = 0;
int now = 0;
int inning[50][10];
bool check[10];
vector<int> player(0);
int solve()
{
	vector<int> game(player);
	game.insert(game.begin()+3, 1);
	int base[4] = { 0, };
	int score = 0;
	for (int x = 0; x < n; x++) {
		int out = 0;
		for (int q = 0; q < 4; q++)
			base[q] = 0;

		while (out < 3) {
			if (inning[x][game[now]] == 0) { // 아웃
				out++;
			}
			else if (inning[x][game[now]] == 1) { // 안타
				if (base[3] == 1) score++;
				base[3] = base[2];
				base[2] = base[1];
				base[1] = 1;
			}
			else if (inning[x][game[now]] == 2) { // 2루타
				if (base[3] == 1) score++;
				base[3] = base[1];
				if (base[2] == 1) score++;
				base[2] = 1;
				base[1] = 0;
			}
			else if (inning[x][game[now]] == 3) { // 3루타
				if (base[3] == 1) score++;
				base[3] = 1;
				if (base[2] == 1) score++;
				if (base[1] == 1) score++;
				base[2] = 0; base[1] = 0;
			}
			else { // 홈런
				for (int i = 1; i < 4; i++) {
					if (base[i] == 1) score++;
					base[i] = 0;
				}
				score++;
			}
			now = (now + 1) % 9;
		}
	}
	return score;
}
void go()
{
	if (player.size() == 8) {
		int aa = solve();
		if (sum < aa)
			sum = aa;
		now = 0;
		return;
	}
	for (int i = 2; i < 10; i++) {
		if (check[i]) continue;
		check[i] = true;
		player.push_back(i);
		go();
		player.pop_back();
		check[i] = false;
	}
}
int main()
{
	freopen("input.txt", "r", stdin);
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> n;
	for (int i = 0; i < n; i++)
		for (int j = 1; j < 10; j++)
			cin >> inning[i][j];
	go();
	cout << sum << endl;
}