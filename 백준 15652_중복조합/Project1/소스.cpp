/*중복조합을 코딩하는 문제*/
#pragma warning(disable : 4996)
#include <iostream>
#include <vector>
using namespace std;

int n, k;
vector<int> rc;

void rpComb(int a, int b)
{
	int i;
	if (b == k) {
		for (i = 0; i < rc.size(); i++)
			cout << rc[i] + 1 << " ";
		cout << "\n";
		return;
	}
	for (i = a; i < n; i++) {
		rc.push_back(i);
		rpComb(i, b + 1);
		rc.pop_back();
	}
}

int main()
{
	cin >> n >> k;
	rpComb(0,0);
}