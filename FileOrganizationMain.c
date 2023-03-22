#include <stdlib.h>
#include <string.h>
#include <stdio.h>
struct
{
    char dname[10], fname[10][10];
    int fcnt;
} dir[10];
void Single()
{
    int i, ch;
    char f[30];
    dir[0].fcnt = 0;
    printf("\nEnter name of directory -- ");
    scanf("%s", dir[0].dname);
    while (1)
    {
        printf("\n\n1. Create File\t2. Delete File\t3. Search File \n 4. Display Files\t5. Exit\nEnter your choice -- ");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            printf("\nEnter the name of the file -- ");
            scanf("%s", dir[0].fname[dir[0].fcnt]);
            dir[0].fcnt++;
            break;
        case 2:
            printf("\nEnter the name of the file -- ");
            scanf("%s", f);
            for (i = 0; i < dir[0].fcnt; i++)
            {
                if (strcmp(f, dir[0].fname[i]) == 0)
                {
                    printf("File %s is deleted ", f);
                    strcpy(dir[0].fname[i], dir[0].fname[dir[0].fcnt - 1]);
                    break;
                }
            }
            if (i == dir[0].fcnt)
                printf("File %s not found", f);
            else
                dir[0].fcnt--;
            break;
        case 3:
            printf("\nEnter the name of the file -- ");
            scanf("%s", f);
            for (i = 0; i < dir[0].fcnt; i++)
            {
                if (strcmp(f, dir[0].fname[i]) == 0)
                {
                    printf("File %s is found ", f);
                    break;
                }
            }
            if (i == dir[0].fcnt)
                printf("File %s not found", f);
            break;
        case 4:
            if (dir[0].fcnt == 0)
                printf("\nDirectory Empty");
            else
            {
                printf("\nThe Files are -- ");
                for (i = 0; i < dir[0].fcnt; i++)
                    printf("\t%s", dir[0].fname[i]);
            }
            break;
        default:
            exit(0);
        }
    }
}
void Two()
{
    int i, ch, dcnt, k;
    char f[30], d[30];
    dcnt = 0;
    while (1)
    {
        printf("\n\n1. Create Directory\t2. Create File\t3. Delete File");
        printf("\n4. Search File\t\t5. Display\t6. Exit\nEnter your choice -- ");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            printf("\nEnter name of directory -- ");
            scanf("%s", dir[dcnt].dname);
            dir[dcnt].fcnt = 0;
            dcnt++;
            printf("Directory created");
            break;
        case 2:
            printf("\nEnter name of the directory -- ");
            scanf("%s", d);
            for (i = 0; i < dcnt; i++)
                if (strcmp(d, dir[i].dname) == 0)
                {
                    printf("Enter name of the file -- ");
                    scanf("%s", dir[i].fname[dir[i].fcnt]);
                    printf("File created");
                    break;
                }
            if (i == dcnt)
                printf("Directory %s not found", d);
            break;
        case 3:
            printf("\nEnter name of the directory -- ");
            scanf("%s", d);
            for (i = 0; i < dcnt; i++)
            {
                if (strcmp(d, dir[i].dname) == 0)
                {
                    printf("Enter name of the file -- ");
                    scanf("%s", f);
                    for (k = 0; k < dir[i].fcnt; k++)
                    {
                        if (strcmp(f, dir[i].fname[k]) == 0)
                        {
                            printf("File %s is deleted ", f);
                            dir[i].fcnt--;
                            strcpy(dir[i].fname[k], dir[i].fname[dir[i].fcnt]);
                            goto jmp;
                        }
                    }
                    printf("File %s not found", f);
                    goto jmp;
                }
            }
            printf("Directory %s not found", d);
        jmp:
            break;
        case 4:
            printf("\nEnter name of the directory -- ");
            scanf("%s", d);
            for (i = 0; i < dcnt; i++)
            {
                if (strcmp(d, dir[i].dname) == 0)
                {
                    printf("\nEnter the name of the file -- ");
                    scanf("%s", f);
                    for (k = 0; k < dir[i].fcnt; k++)
                    {
                        if (strcmp(f, dir[i].fname[k]) == 0)
                        {
                            printf("File %s is found ", f);
                            goto jmp1;
                        }
                    }
                    printf("File %s not found", f);
                    goto jmp1;
                }
            }
            printf("Directory %s not found", d);
        jmp1:
            break;
        case 5:
            if (dcnt == 0)
                printf("\nNo Directory's ");
            else
            {
                printf("\nDirectory\tFiles");
                for (i = 0; i < dcnt; i++)
                {
                    printf("\n%s\t\t", dir[i].dname);
                    for (k = 0; k < dir[i].fcnt; k++)
                        printf("\t%s", dir[i].fname[k]);
                }
            }
            break;
        default:
            exit(0);
        }
    }
}
int main()
{
    int n;
    printf("Enter 1 for Single Level Directory and 2 for Single Level Directory:");
    scanf("%d", &n);
    if (n == 1)
        Single();
    else if (n == 2)
        Two();
    else
        printf("Wrong Input.");
    return -1;
}