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
		cin >> str[i];// 입력받기
		length[i] = str[i].size(); // 각 string의 길이 저장
	}
	for (int i = 0; i < 5; i++) {
		int a = str[i].size();
		if (a > max)
			max = a; //string 중 가장 긴 길이를 가진것을 max에 저장
	}
	for (int j = 0; j < max; j++) {
		for (int i = 0; i < 5; i++) {
			if (j >= length[i]) // j값이 각 string의 길이를 넘으면 지나가기
				continue;
			else
				cout << str[i][j];
		}
	}
	cout << endl;
}