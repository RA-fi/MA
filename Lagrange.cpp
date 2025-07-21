#include <iostream>
using namespace std;
int main() {
    float x[] = {0, 1, 2}, y[] = {1, 3, 2};
    float xp = 1.5, yp = 0;
    for (int i = 0; i < 3; i++) {
        float term = y[i];
        for (int j = 0; j < 3; j++)
            if (j != i) term *= (xp - x[j]) / (x[i] - x[j]);
        yp += term;
    }
    cout << "Interpolated value at x = " << xp << " is " << yp << endl;
}
