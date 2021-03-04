#pragma warning(disable : 4996)
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int n, m;

bool checking(string st) 
{
	int mo = 0, ja = 0;
	for (int i = 0; i < st.size(); i++) { // 모음이면 mo에, 그외에는 ja에 더해준다
		if (st[i] == 'a' || st[i] == 'e' || st[i] == 'i' || st[i] == 'o' || st[i] == 'u')
			mo++;
		else
			ja++;
	}
	return ja >= 2 && mo >= 1;
}

void solve(char al[], string ps, int id)
{
	if (id > m) // id가 al의 정해진 길이 m보다 크면 리턴, 이 위치가 달라지면 조건문의 값도 약간 변경
		return;
	if (ps.size() == n) {  // ps의 사이즈가 맞고
		if(checking(ps))   // 해당 조건에 해당하면 출력
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