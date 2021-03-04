#include <iostream>
using namespace std;

int main()
{
	int dwarf[9];
	int sum = 0;
	int rest,a,b,tmp;
	for (int i = 0; i < 9; i++) {
		cin >> dwarf[i];
		sum += dwarf[i];
	}
	for (int i = 0; i < 9; i++)
	{
		for (int j = i + 1; j < 9; j++)
		{
			if (dwarf[i] > dwarf[j])
			{
				tmp = dwarf[i];
				dwarf[i] = dwarf[j];
				dwarf[j] = tmp;
			}
		}
	}

	for (int i = 0; i < 9; i++)
	{
		for (int j = i + 1; j < 9; j++)
		{
			rest = sum - dwarf[i] - dwarf[j];
			if (rest == 100)
			{
				a = i; b = j;
				break;
			}
		}
	}
	
	for (int i = 0; i < 9; i++)
	{
		if (i == a || i == b)
			continue;
		else
			cout << dwarf[i] << endl;
	}
}