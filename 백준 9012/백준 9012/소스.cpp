#pragma warning(disable : 4996)
#include <iostream>
#include <string>
#include <stack>
using namespace std;

stack<char> stk;

void initializeStack()
{
	while (!stk.empty())
		stk.pop();
}

int main()
{	
	int n, i, j;
	string input;
	cin >> n;
	for (i = 0; i < n; i++) 
	{
		initializeStack();
		cin >> input;
		int num = input.size();
		for (j = 0; j < num; j++) 
		{
			char c = input[j];
			if (c == '(')
				stk.push(c);
			else
			{
				if (!stk.empty() && stk.top() == '(')
					stk.pop();
				else
					stk.push(c);
			}			
		}
		if (stk.empty())
			cout << "YES" << endl;
		else
			cout << "NO" << endl;
	}
}