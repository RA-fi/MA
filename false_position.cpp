#include <iostream>
#include <cmath>
using namespace std;

// Define the function whose root we want to find
double f(double x) {
    return x*x - x - 2;  // Example: f(x) = x³ - x - 2
}

// False Position Method
void falsePosition(double a, double b, double tol, int maxIter) {
    if (f(a) * f(b) >= 0) {
        cout << "Invalid interval f(a) and f(b) must have opposite signs." << endl;
        return;
    }

    double c = a; // Initial approximation
    for (int i = 1; i <= maxIter; ++i) {
        // False position formula
        c = b - (f(b) * (a - b)) / (f(a) - f(b));

        cout << "Iteration " << i << ": c = " << c << ", f(c) = " << f(c) << endl;

        if (fabs(f(c)) < tol) {
            cout << "\nRoot found at x = " << c << " after " << i << " iterations." << endl;
            return;
        }

        // Update the interval
        if (f(a) * f(c) < 0)
            b = c;
        else
            a = c;
    }

    cout << "\nMethod did not converge within the maximum number of iterations." << endl;
}

int main() {
    double a = 1, b = 3;           // Initial guesses
    double tol = 1e-6;             // Tolerance (accuracy)
    int maxIter = 100;            // Maximum number of iterations

    falsePosition(a, b, tol, maxIter);

    return 0;
}
