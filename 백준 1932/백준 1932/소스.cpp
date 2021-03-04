#pragma warning(disable : 4996)
#include <iostream>
using namespace std;

int triangle[500][500];
int tricount[500][500];
int t;

int max(int a, int b)
{
	if (a > b) return a;
	return b;
}

void printf()
{
	for (int i = 0; i < t; i++) {
		for (int j = 0; j <= i; j++)
			cout << tricount[i][j] << " ";
		cout << endl;
	}
}

int main()
{
	freopen("input.txt", "r", stdin);
	int i, j;
	cin >> t;
	for (i = 0; i < t; i++)
		for (j = 0; j <= i; j++)
			cin >> triangle[i][j];
	tricount[0][0] = triangle[0][0];
	int mx = 0;
	for (i = 1; i < t; i++){
		for (j = 0; j <= i; j++) {
			if (j == 0)
				tricount[i][j] = tricount[i - 1][j] + triangle[i][j];
			else if (j == i)
				tricount[i][j] = tricount[i - 1][j - 1] + triangle[i][j];
			else 
				tricount[i][j] = max(tricount[i - 1][j - 1] + triangle[i][j], tricount[i - 1][j] + triangle[i][j]);
			if (tricount[i][j] > mx)
				mx = tricount[i][j];
		}
	}
	printf();
	cout << mx << endl;
}
