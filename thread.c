#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <math.h>

#define NUM_THREADS 5

struct thread_data {
    long number;
    int sum;
};

struct thread_data tda[NUM_THREADS];

void *myThread(void *data) {
    struct thread_data *m;
    m = (struct thread_data *) data;
    printf("Thread #%u working...\n", (int)pthread_self());
    
    long result = m->number * 3;
    m->number = result;

    //printf("\n%i\n", m->number * 2);

    printf("Finished #%lu\n", result);

    return (void *) result;
}

int main() {
    void *status;
    long t;
    int rc;
    pthread_t threads[NUM_THREADS];
    // pthread_attr_t attr;
    // pthread_attr_init(&attr);
    // pthread_attr_setdetachstate(&attr, PTHREAD_CREATE_JOINABLE);

    for(t=0; t<100; t++) {

        tda[t].number = t;
        pthread_create(&threads[t], NULL, myThread, (void*)&tda[t]);
        //printf("After: %lu\n", (long)tda[t].number);

    }

    for(t=0; t<NUM_THREADS; t++) {
        printf("Main: completed with... %lu\n", tda[t].number);
    }

    // pthread_attr_destroy(&attr);
    // for(t=0; t<NUM_THREADS; t++) {
    //     rc = pthread_join(threads[t], &status);

    //     if (rc) {
    //         printf("ERROR; return code from pthread_join() is %d\n", rc);
    //         exit(-1);
    //     }
    //     printf("Main: completed join with thread %ld having a status of %ld\n",t,(long)status);
    // }

    pthread_exit(NULL);
}
