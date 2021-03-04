#pragma warning(disable : 4996)
#include <stdio.h>

long long int fb[91];
void fibo(int a)
{
	int i;
	fb[0] = 0;
	fb[1] = 1;
	for (i = 2; i < a+1; i++) 
	{
		fb[i] = fb[i - 1] + fb[i - 2];
		printf("%lld ", fb[i]);
	}
	printf("\n%lld\n", fb[a]);
}

int main()
{
	int n;
	scanf("%d", &n);
	fibo(n);

	return 0;
}