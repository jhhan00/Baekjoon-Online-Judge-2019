#include <iostream>
using namespace std;

void Find(int x)
{
	if (x == 0) cout << "MON" << endl;
	else if (x == 1) cout << "TUE" << endl;
	else if (x == 2) cout << "WED" << endl;
	else if (x == 3) cout << "THU" << endl;
	else if (x == 4) cout << "FRI" << endl;
	else if (x == 5) cout << "SAT" << endl;
	else cout << "SUN" << endl;
}

int main()
{
	int x, y;
	int hab = 0 , dmo;
	cin >> x >> y;
	if (x == 1)
		hab = y - 1;
	else {
		for (int i = 1; i < x; i++) 
		{
			if (i == 2)
				hab += 28;
			else if (i == 1 || i == 4 || i == 6 || i == 9 || i == 11)
				hab += 30;
			else
				hab += 31;
		}
		hab += y;
	}
	dmo = hab % 7;
	Find(dmo);
}