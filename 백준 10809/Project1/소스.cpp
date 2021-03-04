#pragma warning(disable : 4996)
#include <stdio.h>
#include <string.h>

int kk[26];

void initialize(int aa[])
{
	for (int i = 0; i < 26; i++)
		aa[i] = -1;
}

int main()
{
	char ss[101];	
	int aa;
	printf("문자 입력 : ");
	scanf("%s", &ss);
	aa = strlen(ss);
	initialize(kk);
	printf("%d\n",ss[0]);
	for (int i = 0; i < 26; i++)
	{
		for (int j = 0; j < aa; j++)
		{
			if (ss[j] == i + 97 && kk[i] == -1)
				kk[i] = j;
		}
	}
	for (int i = 0; i < 26; i++)
		printf("%d ", kk[i]);
	printf("\n");

	return 0;
}