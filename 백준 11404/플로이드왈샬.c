#pragma warning(disable : 4996)
#include <stdio.h>
#include <string.h>

int algo[7][7] = { { 0,  4,  5, 99, 99, 99, 99 },
                   { 4,  0,  6,  5, 10, 99, 99 },
                   { 5,  6,  0,  4, 99,  9, 99 },
                   { 99,  5,  4,  0,  6,  3, 99 },
                   { 99, 10, 99,  6,  0,  3,  2 },
                   { 99, 99,  9,  3,  3,  0,  2 },
                   { 99, 99, 99, 99,  2,  2,  0 }, };

int d[7][7];
int nw[7][7];

void printnw()
{
	int i, j;
	for (i = 0; i < 7; i++) 
	{
		for (j = 0; j < 7; j++) 
		{
			printf("%2d ", nw[i][j]);
		}
		printf("\n");
	}
	printf("\n");
}

void alternw()
{
	int i, j;
	for (i = 0; i < 7; i++)
		for (j = 0; j < 7; j++)
			d[i][j] = nw[i][j];
}

int main()
{
	int i, j, k;
	for (i = 0; i < 7; i++)
		for (j = 0; j < 7; j++)
			d[i][j] = algo[i][j];
	for (i = 0; i < 7; i++)
	{
		printf("%d¹ø\n", i+1);
		for (j = 0; j < 7; j++)
		{
			for (k = 0; k < 7; k++)
			{
				if (d[j][k] > d[j][i] + d[i][k])
					nw[j][k] = d[j][i] + d[i][k];
				else
					nw[j][k] = d[j][k];
			}
		}
		printnw();
		alternw();
	}

	return 0;
}