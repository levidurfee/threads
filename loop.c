#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define NUM_THREADS 5

struct prime_data {
    long exponent;
};

int main() {
    pthread_t thread_id[NUM_THREADS];
    int i, j;

}
