#include <stdio.h>
#include <stdlib.h>
void sequential()
{
    int f[50], i, st, j, len, c, k;
    for (i = 0; i < 50; i++)
        f[i] = 0;
X:
    printf("\nEnter the starting block & length of file:");
    scanf("%d%d", &st, &len);
    for (j = st; j < (st + len); j++)
        if (f[j] == 0)
        {
            f[j] = 1;
            printf("\n%d->%d", j, f[j]);
        }
        else
        {
            printf("\nBlock already allocated.");
            break;
        }
    if (j == (st + len))
        printf("\nThe file is allocated to disk:");
    printf("\nEnter 1 to enter more files and 0 to exit:");
    scanf("%d", &c);
    if (c == 1)
        goto X;
    else
        return;
}
void linked()
{
    int f[50], p, i, j, k, a, st, len, n, c;
    for (i = 0; i < 50; i++)
        f[i] = 0;
    printf("Enter how many blocks that are already allocated:");
    scanf("%d", &p);
    printf("\nEnter the blocks no.s that are already allocated:");
    for (i = 0; i < p; i++)
    {
        scanf("%d", &a);
        f[a] = 1;
    }
X:
    printf("Enter the starting index block & length:");
    scanf("%d%d", &st, &len);
    k = len;
    for (j = st; j < (k + st); j++)
    {
        if (f[j] == 0)
        {
            f[j] = 1;
            printf("\n%d->%d", j, f[j]);
        }
        else
        {
            printf("\n %d->File is already allocated.", j);
            k++;
        }
    }
    printf("\nEnter 1 to enter more files and 0 to exit:");
    scanf("%d", &c);
    if (c == 1)
        goto X;
    else
        return;
}
void indexed()
{
    int f[50], i, k, j, inde[50], n, c, count = 0, p;
    for (i = 0; i < 50; i++)
        f[i] = 0;
X:
    printf("Enter index block:");
    scanf("%d", &p);
    if (f[p] == 0)
    {
        f[p] = 1;
        printf("Enter no of files on index:");
        scanf("%d", &n);
    }
    else
    {
        printf("Block already allocated.\n");
        goto X;
    }
    for (i = 0; i < n; i++)
        scanf("%d", &inde[i]);
    for (i = 0; i < n; i++)
        if (f[inde[i]] == 1)
        {
            printf("Block already allocated.");
            goto X;
        }
    for (j = 0; j < n; j++)
        f[inde[j]] = 1;
    printf("\nAllocated.");
    printf("\nFile indexed.");
    for (k = 0; k < n; k++)
        printf("\n %d->%d:%d", p, inde[k], f[inde[k]]);
    printf("\nEnter 1 to enter more files and 0 to exit:");
    scanf("%d", &c);
    if (c == 1)
        goto X;
    else
        return;
}
int main()
{
    int n;
    printf("Enter 1 for Sequential,2 for Linked or 3 for Indexed:");
    scanf("%d", &n);
    if (n == 1)
        sequential();
    else if (n == 2)
        linked();
    else if (n == 3)
        indexed();
    else
        printf("Wrong Input.");
    return -1;
}