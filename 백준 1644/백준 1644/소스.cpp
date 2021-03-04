#pragma warning(disable : 4996)
#include <iostream>
#include <vector>
using namespace std;

int main()
{
	int n;
	cin >> n;
	vector<bool> num(n + 1);
	vector<int> pn;
	for (int i = 2; i <= n; i++) {
		if (!num[i]) {
			pn.push_back(i);
			for (int j = i * 2; j <= n; j += i)
				num[j] = true;
		}
	}
	if (n == 1) {
		cout << 0 << endl;
		return 0;
	}
	int left, right, sum, ans;
	left = right = ans = 0;
	sum = pn[0];
	while (1) {
		if (sum <= n) {
			if (sum == n)
				ans++;			
			right++;
			if (right == pn.size())
				break;
			sum += pn[right];
		}
		else
			sum -= pn[left++];
	}
	cout << ans << endl;
}