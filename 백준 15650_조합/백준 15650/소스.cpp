/*조합을 코딩한 문제*/
#pragma warning(disable : 4996)
#include <iostream>
using namespace std;

int n, k;
int visit[8];

void combination(int a, int b)
{
	int i;
	if (b == k) {
		for (i = 0; i < n; i++)
			if (visit[i])
				cout << i + 1 << " ";
		cout << "\n";
	}
	for (i = a; i < n; i++) {
		if (visit[i]) continue;
		visit[i] = 1;
		combination(i + 1, b + 1);
		visit[i] = 0;
	}
}

int main()
{
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n >> k;
	combination(0, 0);
}