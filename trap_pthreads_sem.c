/*
  trap_pthreads_sem.c
  Trapezoidal Rule Numerical Integrator using pthreads + semaphores (NO OpenMP)

  Command line (required):
      trap_pthreads_sem  number-of-cores  n

  Example:
      trap_pthreads_sem  8  600000000

  Notes:
  - No interactive I/O.
  - Uses a shared global sum; semaphore enforces mutual exclusion in critical section.
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <pthread.h>
#include <semaphore.h>

#include "timer2.h"

/* --------- function to integrate --------- */
double f(double x) {
    return sin(x);
}

/* --------- shared globals --------- */
double a_global = 0.0;
double b_global = 0.0;
long long n_global = 0;
double h_global = 0.0;

double global_sum = 0.0;   /* shared variable */
sem_t sum_sem;             /* semaphore for mutual exclusion */

/* thread args */
typedef struct {
    int tid;
    int thread_count;
} thread_arg_t;

void* trap_worker(void* arg) {
    thread_arg_t* t = (thread_arg_t*) arg;

    int tid = t->tid;
    int thread_count = t->thread_count;

    /* Split i = 1..n-1 among threads (endpoints handled in main) */
    long long i_start = 1 + ( (long long)tid * (n_global - 1) ) / thread_count;
    long long i_end   = ( (long long)(tid + 1) * (n_global - 1) ) / thread_count;

    double local_sum = 0.0;

    for (long long i = i_start; i <= i_end; i++) {
        double x = a_global + (double)i * h_global;
        local_sum += f(x);
    }

    /* critical section: add local_sum into shared global_sum */
    sem_wait(&sum_sem);
    global_sum += local_sum;
    sem_post(&sum_sem);

    return NULL;
}

static void usage(const char* prog) {
    fprintf(stderr,
        "Usage:\n"
        "  %s  number-of-cores  n\n"
        "Example:\n"
        "  %s  8  600000000\n", prog, prog);
}

int main(int argc, char* argv[]) {
    if (argc != 3) {
        usage(argv[0]);
        return 1;
    }

    int thread_count = atoi(argv[1]);
    n_global = atoll(argv[2]);

    if (thread_count <= 0 || n_global <= 1) {
        fprintf(stderr, "Error: number-of-cores must be > 0 and n must be > 1.\n");
        return 1;
    }

    /* Set interval here (no interactive I/O). Change if your assignment specifies different. */
    a_global = 0.0;
    b_global = 10.0;

    h_global = (b_global - a_global) / (double)n_global;

    /* initialize semaphore (shared in-process, initial value 1) */
    sem_init(&sum_sem, 0, 1);

    pthread_t* threads = (pthread_t*) malloc(thread_count * sizeof(pthread_t));
    thread_arg_t* args = (thread_arg_t*) malloc(thread_count * sizeof(thread_arg_t));

    /* Start timer (wall clock) */
    double start, end;
    GET_TIME(start);

    /* Create threads */
    for (int t = 0; t < thread_count; t++) {
        args[t].tid = t;
        args[t].thread_count = thread_count;
        pthread_create(&threads[t], NULL, trap_worker, &args[t]);
    }

    /* Join threads */
    for (int t = 0; t < thread_count; t++) {
        pthread_join(threads[t], NULL);
    }

    /* Add endpoints (done once, serial) */
    global_sum += 0.5 * (f(a_global) + f(b_global));

    double area = global_sum * h_global;

    GET_TIME(end);

    printf("a=%.6f b=%.6f n=%lld threads=%d\n", a_global, b_global, n_global, thread_count);
    printf("Estimated area = %.12f\n", area);
    printf("Execution time = %.6f seconds\n", end - start);

    sem_destroy(&sum_sem);
    free(threads);
    free(args);

    return 0;
}
