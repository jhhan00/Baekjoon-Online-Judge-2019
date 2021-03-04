#pragma warning(disable : 4996)
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	int n, i;
	cin >> n;
	/* ����� pair�� �Ⱦ��� ����
	int *A = new int[n];
	int P[50] = { 0, };

	for (i = 0; i < n; i++) 
		cin >> A[i];
	
	for (i = 0; i < n; i++) {
		for (j = i+1; j < n; j++) {
			if (A[i] > A[j])
				P[i]++;
			else
				P[j]++;
		}
	}
	for (i = 0; i < n; i++)
		cout << P[i] << " ";*/
	//�� �Ʒ����ʹ� pair ���� ����
	//int P[50];
	vector<pair<int, int>> A;
	pair<int, int> value;
	int P[50];

	for (i = 0; i < n; i++) {
		cin >> value.first;
		value.second = i;
		A.push_back(value);
	}

	sort(A.begin(), A.begin() + n);

	for (i = 0; i < n; i++) {
		P[A[i].second] = i;
	}
	
	for (i = 0; i < n; i++) 
		cout << P[i] << " ";
	cout << "\n";
}