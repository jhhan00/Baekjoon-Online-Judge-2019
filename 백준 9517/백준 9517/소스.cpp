#pragma warning(disable : 4996)
#include <iostream>
#define TIME 210
using namespace std;

int nextperson(int a)
{
	if (a == 8) return 1;
	else return a+1;
}
int main()
{
	freopen("input.txt", "r", stdin);
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int k,n;
	cin >> k >> n;
	int limit = 0;
	for (int i = 0; i < n; i++) {
		int tm; char c;
		cin >> tm >> c;
		limit += tm;
		if (limit >= TIME) break;
		if (c != 'T') continue;
		k = nextperson(k);
	}
	cout << k << endl;
}