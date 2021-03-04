#pragma warning(disable : 4996)
#include <iostream>
#include <string>
using namespace std;

int wheel[4][8];
void turnturn(int a, int b)
{
	if (b == 1) { //시계방향회전
		int tmp = wheel[a][0];
		wheel[a][0] = wheel[a][7];
		wheel[a][7] = wheel[a][6];
		wheel[a][6] = wheel[a][5];
		wheel[a][5] = wheel[a][4];
		wheel[a][4] = wheel[a][3];
		wheel[a][3] = wheel[a][2];
		wheel[a][2] = wheel[a][1];
		wheel[a][1] = tmp;
	}
	else { //반시계방향회전
		int tmp = wheel[a][0];
		wheel[a][0] = wheel[a][1];
		wheel[a][1] = wheel[a][2];
		wheel[a][2] = wheel[a][3];
		wheel[a][3] = wheel[a][4];
		wheel[a][4] = wheel[a][5];
		wheel[a][5] = wheel[a][6];
		wheel[a][6] = wheel[a][7];
		wheel[a][7] = tmp;
	}
}
int pw(int k)
{
	return (1 << k);
}
int main()
{
	freopen("input.txt", "r", stdin);
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	string aa[4];
	for (int i = 0; i < 4; i++) {
		cin >> aa[i];
		for (int j = 0; j < 8; j++)
			wheel[i][j] = aa[i][j] - '0';
	}
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int a, b; // a번째 톱니바퀴, b=회전방향
		cin >> a >> b;
		a -= 1;
		if (a == 0) {
			if (wheel[a][2] != wheel[a + 1][6]) {
				if (wheel[a + 1][2] != wheel[a + 2][6]) {
					if (wheel[a + 2][2] != wheel[a + 3][6]) {
						turnturn(a + 3, b*(-1));
					}
					turnturn(a + 2, b);
				}
				turnturn(a + 1, b*(-1));
			}
			turnturn(a, b);
		}
		else if (a == 1) {
			if (wheel[a][6] != wheel[a - 1][2]) {
				turnturn(a - 1, b*(-1));
			}
			if (wheel[a][2] != wheel[a + 1][6]) {
				if (wheel[a + 1][2] != wheel[a + 2][6]) {
					turnturn(a + 2, b);
				}
				turnturn(a + 1, b*(-1));
			}
			turnturn(a, b);
		}
		else if (a == 2) {
			if (wheel[a][2] != wheel[a + 1][6]) {
				turnturn(a + 1, b*(-1));
			}
			if (wheel[a][6] != wheel[a - 1][2]) {
				if (wheel[a - 1][6] != wheel[a - 2][2]) {
					turnturn(a - 2, b);
				}
				turnturn(a - 1, b*(-1));
			}
			turnturn(a, b);
		}
		else if (a == 3) {
			if (wheel[a][6] != wheel[a - 1][2]) {
				if (wheel[a - 1][6] != wheel[a - 2][2]) {
					if (wheel[a - 2][6] != wheel[a - 3][2]) {
						turnturn(a - 3, b*(-1));
					}
					turnturn(a - 2, b);
				}
				turnturn(a - 1, b*(-1));
			}
			turnturn(a, b);
		}
	}
	int ans = 0;
	for (int i = 0; i < 4; i++) {
		if (wheel[i][0] == 1)
			ans += pw(i);
	}
	cout << ans << "\n";
}