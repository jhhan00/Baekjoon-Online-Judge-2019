#include <iostream>
#include <string>
using namespace std;

int main()
{
	string st;
	getline(cin, st);
	int a = st.size();
	int count = 0;
	for (int i = 0; i < a; i++)
	{
		if (st[i] == ' ')
			count++;
	}count++;

	if (st[0] == ' ') { count--; }
	if (st[a - 1] == ' ') { count--; }

	cout << count << endl;
	return 0;
}