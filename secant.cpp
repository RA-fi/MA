#include <iostream>
#include <cmath>
using namespace std;

// Define the function
double f(double x) {
    return x*x*x - x - 2;  // Example: f(x) = x³ - x - 2
}

// Secant Method
void secantMethod(double x0, double x1, double tol, int maxIter) {
    double x2;

    for (int i = 1; i <= maxIter; ++i) {
        double f0 = f(x0);
        double f1 = f(x1);

        if (f1 - f0 == 0.0) {
            cout << "Error: Division by zero. Cannot continue." << endl;
            return;
        }

        // Secant formula
        x2 = x1 - f1 * (x1 - x0) / (f1 - f0);

        cout << "Iteration " << i << ": x = " << x2 << ", f(x) = " << f(x2) << endl;

        if (fabs(x2 - x1) < tol) {
            cout << "\nRoot found at x = " << x2 << " after " << i << " iterations." << endl;
            return;
        }

        // Prepare for next iteration
        x0 = x1;
        x1 = x2;
    }

    cout << "\nMethod did not converge within the maximum number of iterations." << endl;
}

int main() {
    double x0 = 1.0;               // First initial guess
    double x1 = 2.0;               // Second initial guess
    double tol = 1e-6;             // Tolerance
    int maxIter = 100;             // Maximum number of iterations

    secantMethod(x0, x1, tol, maxIter);

    return 0;
}
