#include <iostream>
using namespace std;
int main() {
    float x[] = {1, 2, 3, 4}, y[] = {1.1, 1.9, 3.0, 3.9};
    int n = 4;
    float sumX = 0, sumY = 0, sumXY = 0, sumX2 = 0;
    for (int i = 0; i < n; i++) {
        sumX += x[i]; sumY += y[i];
        sumXY += x[i]*y[i]; sumX2 += x[i]*x[i];
    }
    float b = (n*sumXY - sumX*sumY) / (n*sumX2 - sumX*sumX);
    float a = (sumY - b*sumX)/n;
    cout << "y = " << a << " + " << b << "x\n";
}
