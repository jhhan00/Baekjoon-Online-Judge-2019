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
		sum += x; // ��� ���� �����ֱ�
		if (mxa < x) mxa = x; //�� �� �ִ� ã��
	}
	cin >> m;
	if (m >= sum) { // �պ��� ũ�� �ִ� ���
		cout << mxa << endl;
		return 0;
	}
	int sz = v.size();
	int mx = 0;
	int left = 1, right = m, mid;
	while (left <= right) // �ƴ� ��� �̺�Ž���� ���� �ִ� ã��
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