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
	
	go(id + 1, sum + p[id]);  // �ش� �ε����� ���Ѱ��
	go(id + 1, sum);  //�ش� �ε����� ������ ���� ���
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