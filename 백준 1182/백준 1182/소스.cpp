#pragma warning(disable : 4996)
#include <iostream>
using namespace std;

int n, s, ans=0;
int p[20];

void go(int id, int sum)
{
	if (id == n) {
		if (sum == s)
			ans++;
		return;
	}
	
	go(id + 1, sum + p[id]);  // 해당 인덱스를 더한경우
	go(id + 1, sum);  //해당 인덱스를 더하지 않은 경우
}
int main()
{
	freopen("input.txt", "r", stdin);
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n >> s;
	for (int i = 0; i < n; i++)
		cin >> p[i];
	go(0, 0);
	if (s == 0)
		ans--;
	cout << ans << "\n";
}