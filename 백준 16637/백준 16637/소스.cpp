#pragma warning(disable : 4996)
#include <iostream>
#include <string>
using namespace std;

int N, ans=-987654321987654321;
int num[20];
char ber[20];

int plmimul(int a, int b, char c)
{
	if (c == '+') return a + b;
	else if (c == '-') return a - b;
	else return a * b;
}

void solve(int ix, int result, int op)
{
	if (ix >= op) {
		if (ans < result)
			ans = result;
		return;
	}

	// ix기준으로 제일 처음 2개를 계산
	int temp = plmimul(result, num[ix + 1], ber[ix]);
	cout << "ix : " << ix << ", " << temp << endl;
	solve(ix + 1, temp, op);
	
	if (ix + 1 < op) { // ix기준으로 두번째, 세번째를 먼저 계산
		int tmp2 = plmimul(num[ix + 1], num[ix + 2], ber[ix + 1]);
		temp = plmimul(result, tmp2, ber[ix]);
		cout << "ix : " << ix << ", " << temp << endl;
		solve(ix + 2, temp, op);
	}
}

int main()
{
	freopen("input.txt", "r", stdin);
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> N;
	int ix1 = 0, ix2 = 0;
	for (int i = 0; i < N; i++) {
		char c;
		cin >> c;
		if (c >= '0' && c <= '9')
			num[ix1++] = c - '0';
		else
			ber[ix2++] = c;
	}/*
	for (int a = 0; a < ix1; a++)
		cout << num[a] << " ";
	cout << endl;
	for (int a = 0; a < ix2; a++)
		cout << ber[a] << " ";
	cout << endl;*/
	int opNum = N / 2;
	if (N == 1) {
		cout << num[0];
		return 0;
	}
	if (N == 3) {
		cout << plmimul(num[0], num[1], ber[0]);
		return 0;
	}
	solve(0, num[0], opNum);
	cout << ans;
}