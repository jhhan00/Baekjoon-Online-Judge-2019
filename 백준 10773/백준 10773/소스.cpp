#pragma warning(disable : 4996)
#include <iostream>
#include <stack>
using namespace std;

int main()
{
	stack<int> score;
	int n, m, i;
	cin >> n;
	for (i = 0; i < n; i++) {
		cin >> m;
		if (m == 0)
			score.pop();
		else
			score.push(m);
	}
	int sum = 0;
	while (!score.empty()) {
		sum += score.top();
		score.pop();
	}
	cout << sum << endl;
}