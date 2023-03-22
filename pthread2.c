#include <pthread.h>

#include <stdio.h>

#define n 5

void *PrintHello(void *threadid)

{

    int tid;
    tid = (int)threadid;

    printf("Hello World! It's me, thread #%d!\n", tid);

    pthread_exit(NULL);
}

int main(int argc, char *argv[])

{

    pthread_t threads[n];

    int rc, t;

    for (t = 1; t <= n; t++)

    {

        printf("In main: creating thread %d\n", t);

        rc = pthread_create(&threads[t], NULL, PrintHello, (void *)t);

        if (rc)

        {

            printf("ERROR; return code from pthread_create() is %d\n", rc);

            exit(-1);
        }

        pthread_join(threads[t], NULL);
    }

    pthread_exit(NULL);
}