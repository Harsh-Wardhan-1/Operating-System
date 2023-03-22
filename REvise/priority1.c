#include <stdio.h>
void main()
{
    int limit, x, p[10], pp[10], pt[10], w[10], t[10], awt, att, i;
    limit = 4;
    for (i = 0; i < limit; i++)
    {
        pt[i] = i + 1;
        pp[i] = 7;
        p[i] = i + 1;
    }
    for (i = 0; i < limit - 1; i++)
    {
        for (int j = i + 1; j < limit; j++)
        {
            if (pp[i] < pp[j])
            {
                x = pp[i];
                pp[i] = pp[j];
                pp[j] = x;
                x = pt[i];
                pt[i] = pt[j];
                pt[j] = x;
                x = p[i];
                p[i] = p[j];
                p[j] = x;
            }
        }
    }
    w[0] = 0;
    awt = 0;
    t[0] = pt[0];
    att = t[0];
    for (i = 1; i < limit; i++)
    {
        w[i] = t[i - 1];
        awt += w[i];
        t[i] = w[i] + pt[i];
        att += t[i];
    }
    printf("\n Wait Time : %d \n", awt);
    printf("\n Turn Around Time : %d \n", att);
}
