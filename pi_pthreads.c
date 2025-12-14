/*
  pi_pthreads.c
  Monte Carlo PI computation using pthreads (NO OpenMP)

  Command line:
      pi_pthreads  number-of-cores  number-of-tosses

  Example:
      pi_pthreads  8  500000000
*/

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <stdint.h>

#include "timer2.h"

/* structure to pass data to threads */
typedef struct {
    long long tosses;
    long long count_in_circle;
    unsigned int seed;
} thread_data_t;

/* thread function */
void* toss_darts(void* arg) {
    thread_data_t* data = (thread_data_t*) arg;
    long long local_count = 0;

    for (long long i = 0; i < data->tosses; i++) {
        double x = rand_r(&data->seed) / (double) RAND_MAX;
        double y = rand_r(&data->seed) / (double) RAND_MAX;
        if (x*x + y*y <= 1.0)
            local_count++;
    }

    data->count_in_circle = local_count;
    return NULL;
}

int main(int argc, char* argv[]) {

    if (argc != 3) {
        fprintf(stderr,
            "Usage:\n"
            "  %s  number-of-cores  number-of-tosses\n", argv[0]);
        return 1;
    }

    int thread_count = atoi(argv[1]);
    long long number_of_tosses = atoll(argv[2]);

    if (thread_count <= 0 || number_of_tosses <= 0) {
        fprintf(stderr, "Error: arguments must be positive integers\n");
        return 1;
    }

    pthread_t* threads = malloc(thread_count * sizeof(pthread_t));
    thread_data_t* thread_data = malloc(thread_count * sizeof(thread_data_t));

    long long tosses_per_thread = number_of_tosses / thread_count;

    double start, end;
    GET_TIME(start);

    for (int i = 0; i < thread_count; i++) {
        thread_data[i].tosses = tosses_per_thread;
        thread_data[i].count_in_circle = 0;
        thread_data[i].seed = 1234 + i * 100;

        pthread_create(&threads[i], NULL, toss_darts, &thread_data[i]);
    }

    long long total_in_circle = 0;
    for (int i = 0; i < thread_count; i++) {
        pthread_join(threads[i], NULL);
        total_in_circle += thread_data[i].count_in_circle;
    }

    GET_TIME(end);

    double pi_estimate =
        4.0 * ((double) total_in_circle / (double) number_of_tosses);

    printf("PI estimate = %.6f\n", pi_estimate);
    printf("Execution time = %.6f seconds\n", end - start);

    free(threads);
    free(thread_data);

    return 0;
}
