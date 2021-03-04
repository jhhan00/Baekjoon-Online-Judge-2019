#include <iostream>
using namespace std;

int main()
{
	int n1, n2, x, y;
	int a[3];
	int i = 0;
	cin >> n1 >> n2;
	while (n1 > 0) {
		a[i] = n1 % 10;
		n1 = n1 / 10;
		i++;
	} x = a[0] * 100 + a[1] * 10 + a[2];
	i = 0;
	while (n2 > 0) {
		a[i] = n2 % 10;
		n2 = n2 / 10;
		i++;
	}y = a[0] * 100 + a[1] * 10 + a[2];
	if (x > y)
		cout << x << endl;
	else
		cout << y << endl;
}