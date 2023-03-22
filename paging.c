#include <stdio.h>

int main()
{
    int m, p, nump, np, rp, x, y, add, off;
    int i, j;
    int s[10], fnum[10][20];
    printf("\nEnter the memory size: ");
    scanf("%d", &m);
    printf("\nEnter the page size: ");
    scanf("%d", &p);
    nump = m / p;
    printf("\nTotal number of pages available in memory: %d ", nump);
    printf("\nEnter number of the processes: ");
    scanf("%d", &np);
    rp = nump;
    for (i = 1; i <= np; i++)
    {
        printf("\nEnter the number of pages required for p[%d]: ", i);
        scanf("%d", &s[i]);
        if (s[i] > rp)
        {

            printf("\nMemory is Full.");
            break;
        }
        rp = rp - s[i];

        printf("\nEnter the page table for p[%d]: ", i);
        for (j = 0; j < s[i]; j++)
            scanf("%d", &fnum[i][j]);
    }

    printf("\nEnter the Logical Address to find the Physical Address. ");
    printf("\nEnter the process number, the pagenumber and the offset: ");
    scanf("%d %d %d", &x, &y, &off);

    if (x > np || y >= s[i] || off >= p)
        printf("\nInvalid Process or Page Number or offset");

    else
    {
        add = fnum[x][y] * p + off;
        printf("\nThe Physical Address is: %d", add);
    }
    return -1;
}
