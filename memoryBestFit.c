#include <stdio.h>

void main()
{
    static int barr[20], parr[20];
    int b[20], p[20], frag[20], pn, bn, t, l = 9999;
    printf("\nEnter the no. of blocks:");
    scanf("%d", &bn);
    printf("Enter the no. of processes:");
    scanf("%d", &pn);
    printf("\nEnter the size of the blocks:-\n");
    for (int i = 1; i <= bn; i++)
    {
        printf("Block No.%d:", i);
        scanf("%d", &b[i]);
    }
    printf("\nEnter the size of the processes :-\n");
    for (int i = 1; i <= pn; i++)
    {
        printf("Process No.%d:", i);
        scanf("%d", &p[i]);
    }
    for (int i = 1; i <= pn; i++)
    {
        for (int j = 1; j <= bn; j++)
        {
            if (barr[j] != 1)
            {
                t = b[j] - p[i];
                if (t >= 0)
                    if (l > t)
                    {
                        parr[i] = j;
                        l = t;
                    }
            }
        }
        frag[i] = l;
        barr[parr[i]] = 1;
        l = 10000;
    }
    printf("\nProcess No\tProcess Size\tBlock No\tBlock Size\tFragment");
    for (int i = 1; i <= pn && parr[i] != 0; i++)
        printf("\n%d\t\t%d\t\t%d\t\t%d\t\t%d", i, p[i], parr[i], b[parr[i]], frag[i]);
}