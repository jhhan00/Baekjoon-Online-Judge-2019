#pragma warning(disable : 4996)
#include <iostream>
using namespace std;

void primenumber(int a, int b) 
{
	bool ck;
	for (int j = a; j <= b; j++) {
		ck = false;
		if (j <= 1)
			ck = true;
		else {
			for (int i = 2; i*i <= j; i++) {
				if (j%i == 0) {
					ck = true;
					break;
				}
			}
		}
		if (!ck)
			cout << j << "\n";
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n, m;
	cin >> n >> m;
	primenumber(n, m);	
}