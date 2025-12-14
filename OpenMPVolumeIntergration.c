#include <stdio.h>
#include <math.h>
#include <omp.h>

// Example function f(x,y)
double f(double x, double y) {
    return sin(x) * cos(y);   // Replace this with any z = f(x,y)
}

int main() {
    double a_x, b_x;    // x-interval [a_x, b_x]
    double a_y, b_y;    // y-interval [a_y, b_y]
    int n_x, n_y;       // number of subdivisions in x and y
    double dx, dy;      // grid spacing
    double sum = 0.0;

    printf("Enter ax bx nx: ");
    scanf("%lf %lf %d", &a_x, &b_x, &n_x);

    printf("Enter ay by ny: ");
    scanf("%lf %lf %d", &a_y, &b_y, &n_y);

    dx = (b_x - a_x) / n_x;
    dy = (b_y - a_y) / n_y;

    double start = omp_get_wtime();

    // Parallelize across x-values; reduction accumulates total volume
    #pragma omp parallel for reduction(+:sum)
    for (int i = 0; i < n_x; i++) {
        double x = a_x + i * dx;
        for (int j = 0; j < n_y; j++) {
            double y = a_y + j * dy;
            sum += f(x, y);
        }
    }

    double volume = sum * dx * dy;
    double end = omp_get_wtime();

    printf("Estimated volume = %lf\n", volume);
    printf("Execution time = %lf seconds\n", end - start);

    return 0;
}
