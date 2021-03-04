#pragma warning(disable : 4996)
#include <iostream>
#include <stack>
#include <string>
using namespace std;

int main()
{
	freopen("input.txt", "r", stdin);
	string line;
	cin >> line;
	stack<int> s;
	int sum = 0;
	for (int i = 0; i < line.size(); i++) {
		char c = line[i];
		if (c == '(')
			s.push(i);
		else {
			if (s.top() + 1 == i) {
				s.pop();
				sum += s.size();
			}
			else {
				s.pop();
				sum += 1;
			}
		}
	}
	cout << sum << "\n";
}