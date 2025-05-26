#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

#define MAX 10

void gaussEliminationPartialPivot(int n, double a[MAX][MAX + 1]) {
    // Forward Elimination with Partial Pivoting
    for (int i = 0; i < n - 1; i++) {
        // Partial Pivoting
        int maxRow = i;
        for (int k = i + 1; k < n; k++) {
            if (fabs(a[k][i]) > fabs(a[maxRow][i])) {
                maxRow = k;
            }
        }

        // Swap rows
        if (maxRow != i) {
            for (int j = 0; j <= n; j++) {
                swap(a[i][j], a[maxRow][j]);
            }
        }

        // Elimination
        for (int j = i + 1; j < n; j++) {
            double ratio = a[j][i] / a[i][i];
            for (int k = i; k <= n; k++) {
                a[j][k] -= ratio * a[i][k];
            }
        }
    }

    // Back Substitution
    double x[MAX];
    for (int i = n - 1; i >= 0; i--) {
        x[i] = a[i][n];
        for (int j = i + 1; j < n; j++) {
            x[i] -= a[i][j] * x[j];
        }
        x[i] /= a[i][i];
    }

    // Output solution
    cout << fixed << setprecision(6);
    cout << "\nSolution:\n";
    for (int i = 0; i < n; i++) {
        cout << "x" << i + 1 << " = " << x[i] << endl;
    }
}

int main() {
    int n;
    double a[MAX][MAX + 1];

    cout << "Enter the number of equations: ";
    cin >> n;

    cout << "Enter the augmented matrix (coefficients and constants):\n";
    for (int i = 0; i < n; i++)
        for (int j = 0; j <= n; j++)
            cin >> a[i][j];

    gaussEliminationPartialPivot(n, a);

    return 0;
}
