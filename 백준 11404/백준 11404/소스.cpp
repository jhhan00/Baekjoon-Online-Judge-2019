#pragma warning(disable : 4996)
#include <iostream>
#define MAX 111111
using namespace std;

int bus[101][101];
int cpy[101][101];
int nn;

void copybus()
{
	for (int i = 1; i <= nn; i++)
		for (int j = 1; j <= nn; j++)
			bus[i][j] = cpy[i][j];
}

int main()
{
	freopen("input.txt", "r", stdin);
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	int tt, a, b, c;
	cin >> nn;
	cin >> tt;
	for (int i = 0; i < tt; i++) {
		cin >> a >> b >> c;
		if (bus[a][b] != 0 && bus[a][b] < c)
			continue;
		bus[a][b] = c;
	}
	for (int i = 1; i <= nn; i++)
		for (int j = 1; j <= nn; j++)
			if (i != j && bus[i][j] == 0)
				bus[i][j] = MAX;

	for (int i = 1; i <= nn; i++) {
		for (int j = 1; j <= nn; j++) {
			for (int k = 1; k <= nn; k++) {
				if (bus[j][k] > bus[j][i] + bus[i][k])
					cpy[j][k] = bus[j][i] + bus[i][k];
				else
					cpy[j][k] = bus[j][k];
			}
		}
		copybus();
	}
	for (int i = 1; i <= nn; i++) {
		for (int j = 1; j <= nn; j++) {
			if (bus[i][j] == MAX)
				cout << "0" << " ";
			else
				cout << bus[i][j] << " ";
		}
		cout << endl;
	}
}