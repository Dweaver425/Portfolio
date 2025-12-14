#include <stdio.h>
#include <stdlib.h>
#include <omp.h>

int main(int argc, char* argv[]) {
    long long int number_of_tosses;
    long long int number_in_circle = 0;

    printf("Enter number of darts (tosses): ");
    scanf("%lld", &number_of_tosses);

    double start = omp_get_wtime();

    #pragma omp parallel
    {
        unsigned int seed = 1234 + omp_get_thread_num();

        #pragma omp for reduction(+:number_in_circle)
        for (long long int toss = 0; toss < number_of_tosses; toss++) {
            double x = rand_r(&seed) / (double)RAND_MAX;
            double y = rand_r(&seed) / (double)RAND_MAX;
            double distance = x*x + y*y;

            if (distance <= 1.0)
                number_in_circle++;
        }
    }

    double pi = 4.0 * ((double)number_in_circle / (double)number_of_tosses);
    double end = omp_get_wtime();

    printf("PI estimate = %lf\n", pi);
    printf("Execution time = %lf seconds\n", end - start);

    return 0;
}
