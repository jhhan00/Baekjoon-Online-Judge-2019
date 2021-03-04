#pragma warning(disable : 4996)
#include <iostream>
#include <string>
using namespace std;

int main()
{
	string word;
	cin >> word;
	int n = word.length();
	int start = 0;
	int count = 0;
	while (start < n)
	{
		if (word[start] == 'c')
		{
			if (word[start + 1] == '=' || word[start + 1] == '-')
			{
				start += 2;
				count++;
				continue;
			}
		}
		else if (word[start] == 'd')
		{
			if (word[start + 1] == 'z'&&word[start + 2] == '=')
			{
				start += 3;
				count++;
				continue;
			}
			else if (word[start + 1] == '-')
			{
				start += 2;
				count++;
				continue;
			}
		}
		else if (word[start] == 'l' || word[start] == 'n')
		{
			if (word[start + 1] == 'j')
			{
				start += 2;
				count++;
				continue;
			}
		}
		else if (word[start] == 's' || word[start] == 'z')
		{
			if (word[start + 1] == '=')
			{
				start += 2;
				count++;
				continue;
			}
		}
		start++;
		count++;
	}
	cout << count << endl;
}