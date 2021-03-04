#pragma warning(disable : 4996)
#include <stdio.h>
#include <stdlib.h>

int main()
{
	int n, ctl, i;
	int *arr;
	scanf("%d %d", &n, &ctl);
	arr = (int *)malloc(n*sizeof(int) );
	for (i = 0; i < n; i++)
		scanf("%d", &arr[i]);
	for (i = 0; i < n; i++)
		printf("%d ", arr[i]);
	printf("\n");
	for (i = 0; i < n; i++)
		if (ctl > arr[i])
			printf("%d ", arr[i]);
	free(arr);

	return 0;
}