#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <math.h>
#include "stack.h"

#define NUM_THREADS 5

struct prime_data {
    long exponent;
    double result;
};

struct prime_data pd[NUM_THREADS];


void *prime(void *ptr) {
    //printf("Thread number %ld\n", (long)pthread_self());
    struct prime_data *pd_tmp;
    pd_tmp = (struct prime_data *)ptr;
    long result = pow(2, pd_tmp->exponent);
    return (void *) result;
}

int main() {
    int i, j, k;
    Stack s;
    void *status;
    init(&s, 0x65536); /* Stack of maximum height 0x65536 */
    int l;
    for(l=0; l<20; l++) {
        push(&s, (float)l);
    }

    pthread_t thread_id[NUM_THREADS];
    for(k=0; k< 20 / NUM_THREADS; k++) {
        for(i=0; i < NUM_THREADS; i++) {
            pd[i].exponent = pop(&s);
            pthread_create( &thread_id[i], NULL, prime, (void*)&pd[i] );
            pthread_join( thread_id[i], &status);
            printf("%d\n", (int)status);
        }
    }
    exit(EXIT_SUCCESS);
}
