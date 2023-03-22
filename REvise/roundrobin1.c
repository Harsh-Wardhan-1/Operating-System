#include <stdio.h>
int main()
{
    int i, limit = 4, total = 0, x, counter = 0, tq;
    int wt = 0, tt = 0, at[10], bt[10], temp[10];
    float awt, att;
    x = limit;
    for (i = 0; i < limit; i++)
    {
        at[i] = i + 1;
        bt[i] = 11;
        temp[i] = bt[i];
    }
    tq = 1;
    ;
    for (total = 0, i = 0; x != 0;)
    {
        if (temp[i] <= tq && temp[i] > 0)
        {
            total = total + temp[i];
            temp[i] = 0;
            counter = 1;
        }
        else if (temp[i] > 0)
        {
            temp[i] = temp[i] - tq;
            total = total + tq;
        }
        if (temp[i] == 0 && counter == 1)
        {
            x--;
            wt = wt + total - at[i] - bt[i];
            tt = tt + total - at[i];
            counter = 0;
        }
        if (i == limit - 1)
        {
            i = 0;
        }
        else if (at[i + 1] <= total)
        {
            i++;
        }
        else
        {
            i = 0;
        }
    }
    printf("Waiting Time:\t%d", wt);
    printf("\nurnaround Time:\t%d\n", tt);
    return 0;
}