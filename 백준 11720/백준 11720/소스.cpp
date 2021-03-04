#pragma warning(disable : 4996)
#include <iostream>
#include <string>
using namespace std;

int main()
{
	int n,i;
	int sum = 0;
	string ss;
	cin >> n;
	cin >> ss;
	for (i = 0; i < n; i++) {
		int num = ss[i]-'0';
		sum += num;
	}
	cout << sum << endl;
}