#pragma warning(disable : 4996)
#include <iostream>
#include <string>
using namespace std;

int main()
{
	freopen("input.txt", "r", stdin);
	string str[5];
	int length[5];
	int max = 0;
	for (int i = 0; i < 5; i++) { 
		cin >> str[i];// �Է¹ޱ�
		length[i] = str[i].size(); // �� string�� ���� ����
	}
	for (int i = 0; i < 5; i++) {
		int a = str[i].size();
		if (a > max)
			max = a; //string �� ���� �� ���̸� �������� max�� ����
	}
	for (int j = 0; j < max; j++) {
		for (int i = 0; i < 5; i++) {
			if (j >= length[i]) // j���� �� string�� ���̸� ������ ��������
				continue;
			else
				cout << str[i][j];
		}
	}
	cout << endl;
}