#pragma warning(disable : 4996)
#include <iostream>
using namespace std;

int aa[100000];
int main()
{
	freopen("input.txt", "r", stdin);
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < n; i++)
		cin >> aa[i];
	int left, right, sum, ans;
	left = right = 0;
	sum = aa[0];
	ans = n+1;
	while (right < n) {
		if (sum < m) {
			right++;
			sum += aa[right];
		}
		else {
			int tmp = right - left + 1;
			if (ans > tmp)
				ans = tmp;
			if (left == right) {
				left++; right++;
				sum = aa[right];
			}
			else {
				sum -= aa[left++];
			}
		}
	}
	if (ans == n+1)
		cout << 0 << endl;
	else
		cout << ans << endl;
}