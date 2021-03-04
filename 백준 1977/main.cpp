#include <iostream>
#include <stdio.h>
using namespace std;

int main()
{
    int m, n, mini, sq, a, sum;
    cin >> m >> n;

    for(int i=1; i<=100; i++)
    {
        sq = i*i;
        if(sq >= m && sq <= n)
        {
            mini = sq;
            a = i;
            break;
        }
        mini = -1;
    }

    if(mini == -1)
    {
        printf("-1\n");
        return 0;
    }

    sum = mini;
    for(int i=a+1; i<=100; i++)
    {
        sq = i*i;
        if(sq <= n)
            sum += sq;
        else
            break;
    }

    printf("%d\n%d\n", sum, mini);

    return 0;
}
