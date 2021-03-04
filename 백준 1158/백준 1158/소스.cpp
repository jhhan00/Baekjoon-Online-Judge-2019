#pragma warning(disable : 4996)
#include <iostream>
#include <queue>
using namespace std;

int main() 
{
	queue<int> jo;
	int n, m, i, j;
	cin >> n >> m;
	for (i = 1; i <= n; i++)
		jo.push(i);
	cout << "<";
	for (i = 1; i <= n; i++) {
		for (j = 1; j < m; j++) {
			jo.push(jo.front());
			jo.pop();
		}
		cout << jo.front();
		jo.pop();
		if (i != n)
			cout << ", ";
	}
	cout << ">" << "\n";
}