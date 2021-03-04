#pragma warning(disable : 4996)
#include <stdio.h>

int minimum(int x, int y)
{
	if (x > y)
		return y;
	else
		return x;
}

int main()
{
	int a, b, d, i, n, l;
	scanf("%d", &n);
	for (l = 0; l < n; l++)
	{
		scanf("%d %d", &a, &b);
		if (a == 1) {
			printf("%d\n", b);
			continue;
		}
		else if (b == 1) {
			printf("%d\n", a);
			continue;
		}
		for (i = 1; i <= minimum(a, b); i++)
		{
			if (a%i == 0 && b%i == 0)
				d = i;
		}
		printf("%d\n", d);
		a = a / d; b = b / d;
		printf("%d\n", d*a*b);
	}

	return 0;
}