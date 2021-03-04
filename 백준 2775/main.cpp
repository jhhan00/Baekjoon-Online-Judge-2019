#include <iostream>
#include <stdio.h>
#define MX 15
using namespace std;

int pp[MX][MX];
void person(int fl, int nm)
{
    int i,j;
    for(i=1; i<=fl; i++)
    {
        for(j=1; j<=nm; j++)
        {
            pp[i][j] = pp[i][j-1]+pp[i-1][j];
            //printf("%d ", pp[i][j]);
        }
        //printf("\n");
    }
    printf("%d\n", pp[fl][nm]);
}

int main()
{
    int t, k, n, i;
    for(i=0; i<MX; i++)
        pp[0][i] = i;
    cin >> t;
    for(i=0; i<t; i++)
    {
        cin >> k;
        cin >> n;
        person(k, n);
    }
}
