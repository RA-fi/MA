#include <iostream>
#include <cmath>
using namespace std;
int main() {
    float a[3][4] = {{10, -1, 2, 6}, {-1, 11, -1, 25}, {2, -1, 10, -11}};
    float x[3] = {}, prev[3];
    int i, j, iter = 0;
    do {
        for (i = 0; i < 3; i++) prev[i] = x[i];
        for (i = 0; i < 3; i++) {
            float sum = a[i][3];
            for (j = 0; j < 3; j++)
                if (i != j) sum -= a[i][j] * prev[j];
            x[i] = sum / a[i][i];
        }
        iter++;
    } while (fabs(x[0]-prev[0]) > 0.001 || fabs(x[1]-prev[1]) > 0.001 || fabs(x[2]-prev[2]) > 0.001);
    cout << "Solutions:\n";
    for (i = 0; i < 3; i++) cout << "x" << i+1 << " = " << x[i] << endl;
}
