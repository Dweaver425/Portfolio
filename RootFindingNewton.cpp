#include <iostream>
#include <cmath>

using namespace std;

const double error = .01;
long double newtonMethod(long double x, int iteration);

int main() {
    long double x = 1.0;  
    int iteration = 1;

    long double root = newtonMethod(x, iteration);

    cout << "Approximate root: " << root << endl;
    return 0;
}

long double newtonMethod(long double x, int iteration) {
    long double equ;
    long double ddx;
    long double N1;
    long double rootDiff;

    equ = pow(x, 3) - x - 4; // Change
    ddx = (3 * pow(x, 2)) - 1; // Change
    N1 = x - (equ / ddx);
    rootDiff = N1 - x;


    if (ddx == 0) {  
        cout << "Derivative is zero, Newton's Method fails!" << endl;
        return x;
    }

    

    cout << "Iteration " << iteration 
    << ":\tXn = " << x 
    << "\tF(Xn) = " << equ 
    <<  "\tF'(Xn) = " <<  ddx  
    << "\tXn+1 - Xn = " << rootDiff << endl << endl;

    if (fabs(rootDiff) < error) {  
        return N1;
    }

    return newtonMethod(N1, iteration + 1);  
};
