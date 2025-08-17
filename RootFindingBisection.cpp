#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

const double error = 1e-10;  

long double equ(long double x) {
    return exp(-x) - sin(x); //Change
}

long double bisectionMethod(long double a, long double b, int iteration) {
    if (equ(a) * equ(b) > 0) {
        cout << "No root between [" << a << ", " << b << "]" << endl;
        return NAN;  
    }

    long double c = (a + b) / 2;  

    cout << "Iteration " << iteration << ": a = " << a << ", b = " << b 
         << ", c = " << c << ", f(c) = " << equ(c) 
         << ", |b - a| = " << fabs(b - a) << endl;

    if (fabs(equ(c)) <= error || fabs(b - a) <= error) {
        return c; 
    }

    if (equ(a) * equ(c) < 0) {
        return bisectionMethod(a, c, iteration + 1);
    } else {
        return bisectionMethod(c, b, iteration + 1);
    }
}

int main() {
    long double a = 0, b = 2;  
    int iteration = 1;

    cout << fixed << setprecision(10);
    
    long double root = bisectionMethod(a, b, iteration);

    if (!isnan(root)) {
        cout << "Approximate root: " << root << endl;
    }

    return 0;
}
