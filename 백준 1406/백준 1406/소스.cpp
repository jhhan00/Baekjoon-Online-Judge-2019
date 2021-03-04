#pragma warning(disable : 4996)
#include <iostream>
#include <string>
#include <stack>
using namespace std;

int main()
{
	freopen("input.txt", "r", stdin);
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	string word;  int i, k;  char cc;
	cin >> word;
	stack<char> left, right;
	for (i = 0; i < word.size(); i++)
		left.push(word[i]);
	cin >> k;
	for (i = 0; i < k; i++) {
		cin >> cc;
		if (cc == 'L') {
			if (!left.empty()) {
				right.push(left.top());
				left.pop();
			}
		}
		else if (cc == 'D') {
			if (!right.empty()) {
				left.push(right.top());
				right.pop();
			}
		}
		else if (cc == 'B') {
			if (!left.empty())
				left.pop();
		}
		else if (cc == 'P') {
			char dd;
			cin >> dd;
			left.push(dd);
		}
	}
	while (!left.empty()) {
		right.push(left.top());
		left.pop();
	}
	while (!right.empty()) {
		cout << right.top();
		right.pop();
	}cout << "\n";
}