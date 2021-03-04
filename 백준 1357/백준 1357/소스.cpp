#pragma warning(disable : 4996)
#include <iostream>
using namespace std;

int reverse(int z) 
{
	int b, rv;
	rv = 0;
	while (z > 0) {
		b = z % 10;
		rv = 10 * rv + b;
		z = z / 10;
	}
	return rv;
	
}

int main()
{
	int x, y, a, b, c;
	cin >> x >> y;
	a = reverse(x);
	b = reverse(y);	
	c = reverse(a+b);

	cout << c << endl;
}
