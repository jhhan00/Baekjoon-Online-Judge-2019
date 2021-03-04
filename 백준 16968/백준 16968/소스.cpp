#pragma warning(disable : 4996)
#include <iostream>
#include <string>
using namespace std;

int solve(string &s, int id, char ls)
{
	if (s.size() == id)
		return 1;
	char start, end;
	int ans = 0;
	if (s[id] == 'c') {
		start = 'a';
		end = 'z';
	}
	else {
		start = '0';
		end = '9';
	}
	for (char i = start; i <= end; i++) {
		if (i != ls)
			ans += solve(s, id + 1, i);
	}
	return ans;
}

int main()
{
	string ll;
	cin >> ll;
	cout << solve(ll, 0, ' ') << '\n'; // 브루투 포스의 원리 그래도 이용
	//조합의 원리 이용
	int ans = 1;
	int cnt;
	for (int i = 0; i < ll.size(); i++) {
		if (ll[i] == 'c')
			cnt = 26;
		else
			cnt = 10;
		
		if (i > 0 && ll[i] == ll[i - 1])
			cnt--;
		ans *= cnt;
	}
	cout << ans << endl;
}