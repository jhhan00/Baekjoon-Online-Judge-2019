#pragma warning(disable : 4996)
#include <iostream>
#include <string>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	string s1, s2;
	cin >> s1 >> s2;
	int m1, m2, x1, x2;
	m1 = m2 = x1 = x2 = 0;
	int sz1 = s1.size(); int sz2 = s2.size();
	for (int i = 0; i < sz1; i++) {
		m1 *= 10; x1 *= 10;
		if (s1[i] == '5' || s1[i] == '6') {
			m1 += 5;
			x1 += 6;
		}
		else {
			m1 += s1[i] - '0';
			x1 += s1[i] - '0';
		}
	}
	for (int i = 0; i < sz2; i++) {
		m2 *= 10; x2*= 10;
		if (s2[i] == '5' || s2[i] == '6') {
			m2 += 5;
			x2 += 6;
		}
		else {
			m2 += s2[i] - '0';
			x2 += s2[i] - '0';
		}
	}
	cout << m1 + m2 << ' ' << x1 + x2 << endl;
}