#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define NUM_THREADS 5

struct prime_data {
    long exponent;
};

void *prime(void *ptr) {
    printf("Thread number %ld\n", (long)pthread_self());
    long i = 0;
    return (void *) i;
}

int main() {
    pthread_t thread_id[NUM_THREADS];
    int i, j, k;
    for(k=0; k<100; k++) {
        for(i=0; i < NUM_THREADS; i++) {
            pthread_create( &thread_id[i], NULL, prime, NULL );
        }
        for(j=0; j < NUM_THREADS; j++) {
            pthread_join( thread_id[j], NULL);
        }
    }
}
