#include<iostream>
#include <math.h>
using namespace std;


double func(double x)
{
    return x*x*x - x -1;
}


void bisection(double a,double b, double e)
{
    double xi;
    e=1/pow(10,e);


    if(func(a) * func(b) >= 0)
    {
        cout<<"Incorrect a and b";
        return;
    }

    else {
        
        while ((b - a) >= e) {
            xi = (a + b) / 2;
            if (func(xi) == 0.0) {
                cout << "Root = " << xi << endl;
                break;
            } else if (func(xi) * func(a) < 0) {
                cout << "Root = " << xi << endl;
                b = xi;
            } else {
                cout << "Root = " << xi << endl;
                a = xi;
            }
        }

        cout << "\nAccurate Root calculated is = " << xi;
    }
}


int main()
{
    double a,b,e;
    cout<<"Enter the real value for constant 'a': ";
    cin>>a;
    cout<<"Enter the real value for constant 'b': ";
    cin>>b;
    cout<<"Enter How Much Digit You Want to Match At Decimal Place: ";
    cin>>e;


    printf("The function used is x^3-x-1\n");
    cout<<"a = "<<a<<endl;
    cout<<"b = "<<b<<endl;
    bisection(a,b,e);


    return 0;
}