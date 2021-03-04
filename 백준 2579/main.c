#include <stdio.h>
#include <stdlib.h>

int main()
{
    int t, i;
    scanf("%d", &t);
    int sr[t+1];
    int score[t+1];
    for(i=1; i<=t; i++)
        scanf("%d", &sr[i]);

    for(i=1; i<=t; i++)
    {
        if(i == 1)
            score[i] = sr[i];
        else if(i == 2)
            score[i] = score[1] + sr[i];
        else if(i == 3)
        {
            int s1, s2;
            s1 = sr[1] + sr[3];
            s2 = sr[2] + sr[3];
            if(s1 > s2)
                score[i] = s1;
            else
                score[i] = s2;
        }
        else if(i%2 == 0)
            score[i] = score[i-2] + sr[i];
        else
        {
            int s1, s2;
            s1 = score[i-2] + sr[i];
            s2 = score[i-1] + sr[i];
            if(s1 > s2)
                score[i] = s1;
            else
                score[i] = s2;
        }
    }
    printf("%d\n", score[t]);

    return 0;
}
