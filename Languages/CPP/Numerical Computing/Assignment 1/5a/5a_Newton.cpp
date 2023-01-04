#include <iostream>
#include <math.h>
#include <iomanip>
#define tolerance 0.0000999

using namespace std;


double function(double x){
    return ((x*x*x)-(2*x*x)-5);
}

double derivative(double x){
    return((3*x*x)-(4*x));
}

int main(){
    double a, b, p, prev;
    int n = 0;
    cout << "Enter interval values\n" << endl;
    cout << "Enter a: ";
    cin >> a;
    cout << "Enter b: ";
    cin >> b;

    if(function(a)*function(b) > 0){
        cout << "Root does not between the interval" << endl;
        exit(1);
    }

    p = (b+a)/2;

    system ("clear");
    cout << setw(2) << right << "n" << setw(20) << right << "P" << setw(20) << right << "P(next)" << setw(20) << right << "|P(n)-P(n-1)|" << setw(20) << right << "f(p)" << endl << endl;
    do{
        prev = p;
        p -= (function(p)/derivative(p));
        cout << setprecision(10) << setw(2) << right << n << setw(20) << right << prev << setw(20) << right << p << setw(20) << right << abs(p-prev) << setw(20) << right << function(p) << endl;
        n++;
    }while(abs(p-prev) >= tolerance);
    return 0;
}