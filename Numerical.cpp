#include <iostream>
using namespace std;
float f(float x) { return x*x + 2*x + 1; } // f(x) = x² + 2x + 1
int main() {
    float x = 2, h = 0.01;
    float forward = (f(x + h) - f(x)) / h;
    float central = (f(x + h) - f(x - h)) / (2*h);
    float backward = (f(x) - f(x - h)) / h;
    cout << "Backward Derivative ≈ " << backward << "\n";
    cout << "Forward Derivative ≈ " << forward << "\n";
    cout << "Central Derivative ≈ " << central << "\n";
}
