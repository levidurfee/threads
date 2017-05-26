#include <stdio.h>
#include <pthread.h>

#define NUM_THREADS 8

void *myThread()
{
    printf("Thread #%u working on task1\n", (int)pthread_self());
    return (void *) 42;
}

int main() {
    pthread_t tid;
    void *status;

    pthread_create(&tid, NULL, myThread, NULL);
    pthread_join(tid, &status);

    printf("%d\n",(int)status);

    return 0;
}
