#pragma warning(disable : 4996)
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int n, m;

bool checking(string st) 
{
	int mo = 0, ja = 0;
	for (int i = 0; i < st.size(); i++) { // �����̸� mo��, �׿ܿ��� ja�� �����ش�
		if (st[i] == 'a' || st[i] == 'e' || st[i] == 'i' || st[i] == 'o' || st[i] == 'u')
			mo++;
		else
			ja++;
	}
	return ja >= 2 && mo >= 1;
}

void solve(char al[], string ps, int id)
{
	if (id > m) // id�� al�� ������ ���� m���� ũ�� ����, �� ��ġ�� �޶����� ���ǹ��� ���� �ణ ����
		return;
	if (ps.size() == n) {  // ps�� ����� �°�
		if(checking(ps))   // �ش� ���ǿ� �ش��ϸ� ���
			cout << ps << "\n";
		return;
	}
	solve(al, ps+al[id], id + 1);
	solve(al, ps, id + 1);
}

int main()
{
	freopen("input.txt", "r", stdin);
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n >> m;
	char pw[15];
	for (int i = 0; i<m; i++)
		cin >> pw[i];
	sort(pw, pw + m);
	string password = "";
	solve(pw, password, 0);
}