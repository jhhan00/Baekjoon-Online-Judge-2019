#pragma warning(disable : 4996)
#include <iostream>
using namespace std;

int ballcatch[1002] = {0,};
int main()
{
	freopen("input.txt", "r", stdin);
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	int n, m, l;
	cin >> n >> m >> l;
	int throwing_count=0;
	int now = 1;
	bool check = false;
	while (1) {
		ballcatch[now]++;
		for (int i = 1; i <= n; i++) {
			if (ballcatch[i] == m)
				check = true;
		}
		if (check) break;
		if (ballcatch[now] % 2 == 1) // 홀수일때는 시계방향
		{
			now = now + l;
			if (now > n)
				now = now - n;			
		}
		else  // 짝수일때는 반시계방향
		{
			now = now - l;
			if (now < 1)
				now = now + n;
		}
		throwing_count++;		
	}
	cout << throwing_count << endl;
}