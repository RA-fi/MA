#include <iostream>
using namespace std;
float f(float x) { return 1/(1 + x*x); } // Example: f(x) = 1/(1+x²)
int main() {
    float a = 0, b = 1, h = (b - a) / 6, sum = f(a) + f(b);
    for (int i = 1; i < 6; i++)
        sum += (i % 2 == 0 ? 2 : 4) * f(a + i*h);
    cout << "Integral = " << (h/3)*sum << endl;
}
