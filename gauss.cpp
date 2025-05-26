#include <iostream>
#include <iomanip>
using namespace std;

// Gauss Elimination without pivoting
void gaussElimination(int n, double a[10][11]) {
    // Forward Elimination
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            double ratio = a[j][i] / a[i][i];
            for (int k = i; k <= n; k++) {
                a[j][k] -= ratio * a[i][k];
            }
        }
    }

    // Back Substitution
    double x[10];
    for (int i = n - 1; i >= 0; i--) {
        x[i] = a[i][n];
        for (int j = i + 1; j < n; j++) {
            x[i] -= a[i][j] * x[j];
        }
        x[i] /= a[i][i];
    }

    // Output the solution
    cout << fixed << setprecision(6);
    cout << "\nSolution:\n";
    for (int i = 0; i < n; i++) {
        cout << "x" << i + 1 << " = " << x[i] << endl;
    }
}

int main() {
    int n;
    double a[10][11];

    cout << "Enter number of equations: ";
    cin >> n;

    cout << "Enter the augmented matrix (coefficients + constants):\n";
    for (int i = 0; i < n; i++)
        for (int j = 0; j <= n; j++)
            cin >> a[i][j];

    gaussElimination(n, a);

    return 0;
}
