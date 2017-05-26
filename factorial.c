#include <stdio.h>
#include <pthread.h>

#define NUM_THREADS 8

struct thread_data {
    int thread_id;
    int number;
    int sum;
};

struct thread_data thread_data_array[NUM_THREADS];

long int factorial(int n);
void *PrintHello(void *threadid);

int main() {
    long int r;
    r = factorial(5);
    printf("%li\n", r);

    pthread_t threads[NUM_THREADS];

    int rc;
    long t;
    for(t=0; t<NUM_THREADS; t++){
       printf("In main: creating thread %ld\n", t);
       thread_data_array[t].thread_id = t;
       rc = pthread_create(&threads[t], NULL, PrintHello, (void *)&thread_data_array[t]);
       if (rc){
          printf("ERROR; return code from pthread_create() is %d\n", rc);
       }
    }

    /* Last thing that main() should do */
    pthread_exit(NULL);
}

long int factorial(int n) {
    if (n >= 1)
        return n*factorial(n-1);
    else
        return 1;
}

void *PrintHello(void *threadarg) {
    struct thread_data *my_data;
    my_data = (struct thread_data *) threadarg;
    long int tid = my_data->thread_id;
    printf("Hello World! It's me, thread #%ld!\n", tid);
    pthread_exit(NULL);
}
