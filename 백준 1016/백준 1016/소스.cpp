#pragma warning(disable : 4996)
#include <iostream>
using namespace std;

bool pn[1000001];
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	long long mn, mx;
	cin >> mn >> mx;
	for (long long i = 2; i*i <= mx; i++) {
		long long ss = mn / (i*i);
		if (ss*i*i != mn) ss++;
		for (long long j = ss; j*i*i <= mx; j++)
			pn[j*i*i - mn] = true;
	}
	int ans = 0;
	long long aa = mx - mn + 1;
	for (long long i = 0; i < aa; i++)
		if (pn[i] == false)
			ans++;
	cout << ans << endl;
}