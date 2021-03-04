#pragma warning(disable : 4996)
#include <iostream>
#define MAX 1001
using namespace std;

int main()
{
	int n, i;
	int dp[MAX];
	dp[1] = 1;
	dp[2] = 2;
	for (i = 3; i < MAX; i++) {
		dp[i] = dp[i - 1] + dp[i - 2];
		dp[i] = dp[i] % 10007;
	}
	scanf("%d", &n);
	printf("%d\n",dp[n]);
}