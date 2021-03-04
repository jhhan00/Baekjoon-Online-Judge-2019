#pragma warning(disable : 4996)
#include <iostream>
#include <vector>
using namespace std;

vector<int> comb;
int a[15];
int n;

void go(int id, int cnt)
{
	if (cnt == 6) {
		for (int i : comb)
			printf("%d ", i);
		printf("\n");
		return;
	}
	if (id == n) return;

	comb.push_back(a[id]);
	go(id + 1, cnt + 1); // 선택
	comb.pop_back();
	go(id + 1, cnt); //선택하지 않음
}

int main()
{
	freopen("input.txt", "r", stdin);
	while (1) {
		cin >> n;
		if (n == 0)
			break;
		for (int i = 0; i < n; i++)
			cin >> a[i];
		go(0, 0);
		cout << "\n";
	}	
}