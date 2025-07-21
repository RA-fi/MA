#include <iostream>
using namespace std;
float f(float x) { return x*x; } // Example: f(x) = x²
int main() {
    float a = 0, b = 1;
    int n = 4;
    float h = (b - a)/n, sum = f(a) + f(b);
    for (int i = 1; i < n; i++) sum += 2*f(a + i*h);
    cout << "Integral = " << (h/2)*sum << endl;
}
