#pragma warning(disable : 4996)
#include <iostream>
using namespace std;

int sum;
bool ch[1501][1501];
void bfs(int a, int b);
int main()
{
	int x, y, z;
	cin >> x >> y >> z;
	sum = x + y + z;
	if (sum % 3 != 0) {
		cout << 0 << '\n';
		return 0;
	}
	bfs(x, y);
	cout << ch[sum / 3][sum / 3] << '\n';
}
void bfs(int a, int b)
{
	if (ch[a][b]) return; // 무한루프방지
	ch[a][b] = true;
	int k[3] = { a,b,sum - a - b };
	for (int i = 0; i < 3; i++) {
		for (int j = i+1; j < 3; j++) {			
			if (k[i] < k[j]) {
				int k1[3] = { a,b,sum - a - b };
				k1[i] += k[i];
				k1[j] -= k[i];
				bfs(k1[i], k1[j]);
			}
			else {
				int k2[3] = { a,b,sum - a - b };
				k2[i] -= k[j];
				k2[j] += k[j];
				bfs(k2[i], k2[j]);
			}
		}
	}
}