#include <stdio.h>
int LRU(int t[], int n)
{
    int min = t[0], pos = 0;
    for (int i = 1; i < n; ++i)
    {
        if (t[i] < min)
        {
            min = t[i];
            pos = i;
        }
    }
    return pos;
}
int main()
{
    int nf, np, f[10], p[30], c = 0, t[10];
    int f1, f2, pos, fault = 0;
    int i, j;
    printf("Enter the number of frames: ");
    scanf("%d", &nf);
    printf("Enter the number of pages: ");
    scanf("%d", &np);
    printf("Enter reference string: ");
    for (i = 0; i < np; ++i)
    {
        scanf("%d", &p[i]);
    }

    for (i = 0; i < nf; ++i)
    {
        f[i] = -1;
    }

    for (i = 0; i < np; ++i)
    {
        f1 = f2 = 0;

        for (j = 0; j < nf; ++j)
        {
            if (f[j] == p[i])
            {
                c++;
                t[j] = c;
                f1 = f2 = 1;
                break;
            }
        }

        if (f1 == 0)
        {
            for (j = 0; j < nf; ++j)
            {
                if (f[j] == -1)
                {
                    c++;
                    fault++;
                    f[j] = p[i];
                    t[j] = c;
                    f2 = 1;
                    break;
                }
            }
        }

        if (f2 == 0)
        {
            pos = LRU(t, nf);
            c++;
            fault++;
            f[pos] = p[i];
            t[pos] = c;
        }

        printf("\n");

        for (j = 0; j < nf; ++j)
        {
            printf("%d\t", f[j]);
        }
    }
    printf("\n\nTotal Page Faults = %d", fault);
    return 0;
}