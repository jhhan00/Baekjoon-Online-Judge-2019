#pragma warning(disable : 4996)
#include <stdio.h>

int fb[50];
int fibonacci(int d);

int main()
{
	int n, i, k;
	scanf("%d", &n);	
	
	fibonacci(40);
	for (i = 0; i < n; i++)
	{
		scanf("%d", &k);
		if (k == 0)
			printf("%d %d\n", fb[1], fb[0]);
		else if (k == 1)
			printf("%d %d\n", fb[0], fb[1]);
		else
			printf("%d %d\n", fb[k - 1], fb[k]);
	}

	return 0;
}

int fibonacci(int d)
{
	int i;
	fb[0] = 0;
	fb[1] = 1;

	for (i = 2; i < d; i++)
	{
		fb[i] = fb[i - 1] + fb[i - 2];
	}
}
