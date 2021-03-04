#include <iostream>
using namespace std;

int main()
{
	int N;
	int a5 = 0;
	int b3 = 0;
	cin >> N;
	while (N > 0) 
	{
		if (N % 5 == 0) {
			N = N - 5;
			a5++;
		}
		else {
			N = N - 3;
			b3++;
		}
	}
	if (N != 0) {
		cout << "-1" << endl;
		return 0;
	}
	else {
		cout << a5 + b3 << endl;
		return 0;
	}
}