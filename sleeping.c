#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <time.h>
#include <pthread.h>
#include <semaphore.h>

#define max 20
void *customers(void *num);
void *barber(void *);
void wait(int sec);
sem_t chair;
sem_t pillow;
sem_t waitroom;
sem_t sb;
int fin = 0;

void *customers(void *number)
{
    int n = *(int *)number;
    printf("The customer %d is leaving for the barber shop.\n", n);
    wait(2);
    printf("The customer %d has reached the barber shop.\n", n);
    sem_wait(&waitroom);
    printf("The customer %d is entering the waiting room.\n", n);
    sem_wait(&chair);
    sem_post(&waitroom);
    printf("The customer %d is waking the barber.\n", n);
    sem_post(&pillow);
    sem_wait(&sb);
    sem_post(&chair);
    printf("The customer %d is leaving the barber shop.\n", n);
}

void *barber(void *junk)
{
    while (!fin)
    {
        printf("The barber is sleeping\n");
        sem_wait(&pillow);
        if (!fin)
        {
            printf("The barber is cutting the hair\n");
            wait(2);
            printf("The barber has completed cutting the hair.\n");
            sem_post(&sb);
        }
        else
        {
            printf("The barber is going.\n");
        }
    }
}
void wait(int sec)
{
    int length;
    length = (int)((1 * sec) + 1);
    sleep(length);
}

int main(int argc, char *argv[])
{

    pthread_t tid[max];
    pthread_t btid;
    long seed;
    int i;
    int numcust = 5, noc = 1;
    int number[max];
    if (numcust > max)
    {
        printf("The max no. of customers is %d.\n", max);
        exit(-1);
    }
    for (i = 0; i < max; i++)
    {
        number[i] = i;
    }
    sem_init(&waitroom, 0, noc);
    sem_init(&chair, 0, 1);
    sem_init(&pillow, 0, 0);
    sem_init(&sb, 0, 0);
    pthread_create(&btid, NULL, barber, NULL);
    for (i = 0; i < numcust; i++)
    {
        pthread_create(&tid[i], NULL, customers, (void *)&number[i]);
        sleep(1);
    }
    for (i = 0; i < numcust; i++)
    {
        pthread_join(tid[i], NULL);
        sleep(1);
    }
    fin = 1;
    sem_post(&pillow);
    pthread_join(btid, NULL);
}
