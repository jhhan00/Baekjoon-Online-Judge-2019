#include <iostream>
using namespace std;

int main()
{
	int n,b,c,d;
	int count = 0;
	cin >> n;
	int a = n;
	while (1) {
		b = a % 10;
		c = a / 10;
		d = b + c;
		if (d >= 10)
			d = d % 10;
		a = b * 10 + d;
		count++;
		if (a == n)
			break;
	}
	cout << count << endl;
}