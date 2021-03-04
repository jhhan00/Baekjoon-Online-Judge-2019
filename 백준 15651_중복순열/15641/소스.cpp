/*중복순열을 코딩한 문제*/
#pragma warning(disable : 4996)
#include <iostream>
#include <vector>
using namespace std;

int n, k;
vector<int> rp;

void repeatPer(int s)
{
	int i;
	if (s == k) {
		for (i = 0; i < rp.size(); i++)
			cout << rp[i] << " ";
		cout << "\n";
		return;
	}
	for (i = 0; i < n; i++) {
		rp.push_back(i + 1);
		repeatPer(s+1);
		rp.pop_back();
	}
}

int main()
{
	cin >> n >> k;
	repeatPer(0);
}