#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <time.h>

int thread_count;
long long total_tosses;
long long number_in_circle = 0;

pthread_mutex_t mutex;

void* MonteCarlo(void* rank) {
    long my_rank = (long) rank;
    long long local_tosses;
    long long local_count = 0;

    long long q = total_tosses / thread_count;
    long long r = total_tosses % thread_count;

    if (my_rank < r)
        local_tosses = q + 1;
    else
        local_tosses = q;

    unsigned int seed = time(NULL) + my_rank;

    for (long long i = 0; i < local_tosses; i++) {
        double x = (double) rand_r(&seed) / RAND_MAX * 2.0 - 1.0;
        double y = (double) rand_r(&seed) / RAND_MAX * 2.0 - 1.0;

        double distance_squared = x * x + y * y;

        if (distance_squared <= 1.0)
            local_count++;
    }

    pthread_mutex_lock(&mutex);
    number_in_circle += local_count;
    pthread_mutex_unlock(&mutex);

    return NULL;
}

int main(int argc, char* argv[]) {
    if (argc != 3) {
        printf("Usage: %s <number of threads> <number of tosses>\n", argv[0]);
        return 0;
    }

    thread_count = atoi(argv[1]);
    total_tosses = atoll(argv[2]);

    pthread_t* thread_handles;
    thread_handles = malloc(thread_count * sizeof(pthread_t));

    pthread_mutex_init(&mutex, NULL);

    for (long thread = 0; thread < thread_count; thread++)
        pthread_create(&thread_handles[thread], NULL, MonteCarlo, (void*) thread);

    for (long thread = 0; thread < thread_count; thread++)
        pthread_join(thread_handles[thread], NULL);

    double pi_estimate = 4.0 * number_in_circle / (double) total_tosses;

    printf("Estimated pi = %f\n", pi_estimate);

    pthread_mutex_destroy(&mutex);
    free(thread_handles);

    return 0;
}
