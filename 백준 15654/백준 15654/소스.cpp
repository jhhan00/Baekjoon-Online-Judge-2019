/*숫자가 지정된 순열... 이게 순열인가..? ㅋㅋ*/
#pragma warning(disable : 4996)
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, k;
int num[8], visit[8];
vector<int> pp;

void Permutation(int a)
{
	int i;
	if (a == k) {
		for (i = 0; i < k; i++)
			cout << pp[i] << " ";
		cout << "\n";
		return;
	}
	for (i = 0; i < n; i++) {
		if (visit[i]) continue;
		visit[i] = 1;
		pp.push_back(num[i]);
		Permutation(a + 1);
		pp.pop_back();
		visit[i] = 0;
	}
}

int main()
{
	cin >> n >> k;
	for (int i = 0; i < n; i++)
		cin >> num[i];
	sort(num, num + n);
	Permutation(0);
}