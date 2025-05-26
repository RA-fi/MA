#include <iostream>
#include <cmath>
using namespace std;

// Define the function
double f(double x) {
    return x*x*x - x - 2;  // Example: f(x) = x³ - x - 2
}

// Define the derivative of the function
double f_derivative(double x) {
    return 3*x*x - 1;  // f'(x) = 3x² - 1
}

// Newton-Raphson Method
void newtonRaphson(double x0, double tol, int maxIter) {
    double x = x0;
    
    for (int i = 1; i <= maxIter; ++i) {
        double fx = f(x);
        double fdx = f_derivative(x);
        
        if (fdx == 0.0) {
            cout << "Error: Derivative is zero at x = " << x << ". Cannot continue." << endl;
            return;
        }

        double x1 = x - fx / fdx;

        cout << "Iteration " << i << ": x = " << x1 << ", f(x) = " << f(x1) << endl;

        if (fabs(x1 - x) < tol) {
            cout << "\nRoot found at x = " << x1 << " after " << i << " iterations." << endl;
            return;
        }

        x = x1;
    }

    cout << "\nMethod did not converge within the maximum number of iterations." << endl;
}

int main() {
    double x0 = 1.5;               // Initial guess
    double tol = 1e-6;             // Tolerance
    int maxIter = 100;             // Maximum iterations

    newtonRaphson(x0, tol, maxIter);

    return 0;
}
