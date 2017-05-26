#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include "stack.h"

#define NUM_THREADS 5

struct prime_data {
    long exponent;
};

struct prime_data pd[NUM_THREADS];


void *prime(void *ptr) {
    printf("Thread number %ld\n", (long)pthread_self());
    long i = 0;
    return (void *) i;
}

int main() {
    int i, j, k, l;
    Stack s;
    init(&s, 0x65536); /* Stack of maximum height 0x65536 */
    for(l=0; l<20; l++) {
        push(&s, l + 2);
    }

    pthread_t thread_id[NUM_THREADS];
    for(k=0; k<20; k++) {
        for(i=0; i < NUM_THREADS; i++) {
            pd[i].exponent = pop(&s);
            pthread_create( &thread_id[i], NULL, prime, NULL );
        }
        for(j=0; j < NUM_THREADS; j++) {
            pthread_join( thread_id[j], NULL);
        }
    }
}
