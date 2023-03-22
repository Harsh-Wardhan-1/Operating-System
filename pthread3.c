#include <stdio.h>
#include <time.h>
#include <pthread.h>

void *summation(void *n)
{
    int *x = (int *)n;
    printf("Function called\n");
    int count = 0;
    for (int i = 1; i <= *x; i++)
    {
        count++;
    }
}
int main()
{
    pthread_t tid1;
    pthread_t tid2;
    int n = 750000;
    clock_t t1;

    t1 = clock();
    pthread_create(&tid1, NULL, summation, &n);
    pthread_join(tid1, NULL);

    pthread_create(&tid2, NULL, summation, &n);
    pthread_join(tid2, NULL);

    t1 = clock() - t1;
    double tt = ((double)t1) / CLOCKS_PER_SEC;
    printf("Time taken: %f seconds\n", tt);
    t1 = clock();
    summation(&n);
    summation(&n);
    t1 = clock() - t1;
    tt = ((double)t1) / CLOCKS_PER_SEC;
    printf("Time taken: %f seconds\n", tt);
}