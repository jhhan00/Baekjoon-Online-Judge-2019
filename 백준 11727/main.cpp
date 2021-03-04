#include <cstdio>
using namespace std;

int main()
{
    int n,i;
    int dp[1001];
    dp[1]=1;
    dp[2]=3;
    for(i=3; i<1001; i++) {
        dp[i] = dp[i-1] + 2 * dp[i-2];
        dp[i] %= 10007;
    }
    scanf("%d", &n);
    printf("%d\n", dp[n]);
}
