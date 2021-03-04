#pragma warning(disable : 4996)
#include <iostream>
#include <vector>
using namespace std;

int n, m;
int mp[51][51];
bool ch[51][51];
int ans = 0;
vector<int> hx; vector<int> hy;
void mini_distance(vector<int> &a, vector<int> &b)
{ // ���� ġŲ���� ��ġ�� �ּҰŸ� ����
	int sum = 0;
	for (int i = 0; i < hx.size(); i++) {
		int mini = 0;
		for (int j = 0; j < a.size(); j++) {
			int dx = hx[i] - a[j];
			int dy = hy[i] - b[j];
			if (dx < 0) dx = -dx;
			if (dy < 0) dy = -dy;
			if (mini == 0 || mini > dx + dy)
				mini = dx + dy;
		}
		sum += mini;
	}
	if (ans == 0 || ans > sum)
		ans = sum;
}
void chicken(int a, int cnt) // ġŲ�� ����
{
	if (cnt == m) { // ġŲ���� ��� �������� ��
		vector<int> vx; vector<int> vy;
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				if (ch[i][j]) { // �� ���� ġŲ�� ��ġ ����
					vx.push_back(i);
					vy.push_back(j);
				}
			}
		}
		mini_distance(vx, vy);
		return;
	}
	//������ ������
	for (int i = a; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (mp[i][j] == 2 && ch[i][j] == false) {
				ch[i][j] = true;
				chicken(i, cnt+1);
				ch[i][j] = false;
			}
		}
	}
}
int main()
{
	freopen("input.txt", "r", stdin);
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> mp[i][j];
			if (mp[i][j] == 1) { // ���� ��� ��ġ ���� ����
				hx.push_back(i);
				hy.push_back(j);
			}
		}
	}
	chicken(1, 0);
	cout << ans << '\n';
}