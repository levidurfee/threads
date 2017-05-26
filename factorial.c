#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define NUM_THREADS 8

void *myThread()
{
    printf("Thread #%u working...\n", (int)pthread_self());
    return (void *) 42;
}

int main() {
    void *status;
    long t;
    int rc;
    pthread_t threads[NUM_THREADS];
    pthread_attr_t attr;

    pthread_attr_init(&attr);
    pthread_attr_setdetachstate(&attr, PTHREAD_CREATE_JOINABLE);

    for(t=0; t<NUM_THREADS; t++){

        pthread_create(&threads[t], &attr, myThread, NULL);
        printf("%d\n",(int)status);

    }

    pthread_attr_destroy(&attr);
    for(t=0; t<NUM_THREADS; t++) {
        rc = pthread_join(threads[t], &status);
        if (rc) {
            printf("ERROR; return code from pthread_join() is %d\n", rc);
            exit(-1);
        }
        printf("Main: completed join with thread %ld having a status of %ld\n",t,(long)status);
    }

    pthread_exit(NULL);
}
