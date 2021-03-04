#pragma warning(disable : 4996)
#include <iostream>
#include <vector>
using namespace std;

int main()
{
	freopen("input.txt", "r", stdin);
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	int n, m, sum = 0, mxa = 0;
	cin >> n;
	vector<int> v;
	for (int i = 0; i < n; i++) {
		int x; cin >> x;
		v.push_back(x);
		sum += x; // 모든 값들 더해주기
		if (mxa < x) mxa = x; //그 중 최댓값 찾기
	}
	cin >> m;
	if (m >= sum) { // 합보다 크면 최댓값 출력
		cout << mxa << endl;
		return 0;
	}
	int sz = v.size();
	int mx = 0;
	int left = 1, right = m, mid;
	while (left <= right) // 아닌 경우 이분탐색을 통해 최댓값 찾기
	{
		int tmp = 0;
		mid = (left + right) / 2;
		for (int i = 0; i < sz; i++) {
			if (mid > v[i])
				tmp += v[i];
			else
				tmp += mid;
		}
		if (tmp == m) {
			mx = mid;
			break;
		}
		else if (tmp > m) {
			right = mid - 1;
		}
		else {
			if (mx < mid)
				mx = mid;
			left = mid + 1;
		}
	}
	cout << mx;
}