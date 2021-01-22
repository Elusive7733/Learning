#include <iostream>
#include <math.h>
#include <iomanip>
#define tolerance 0.0000999

using namespace std;

double function(double x){
    return ((x*x*x)-(2*x*x)-5);
}

int main(){
    double a, b, p0, p1;
    int n = 0;
    p1 = 0;
    cout << "Enter interval values\n" << endl;
    cout << "Enter a: ";
    cin >> a;
    cout << "Enter b: ";
    cin >> b;

    if(function(a)*function(b) > 0){
        cout << "Root does not between the interval" << endl;
        exit(1);
    }

    system ("clear");
    cout << setw(2) << right << "n" << setw(20) << right << "a" << setw(20) << right << "b" << setw(20) << right << "P" << setw(20) << right << "|P(n)-P(n-1)|" << setw(20) << right << "f(p)" << endl << endl;
    do{
        p0 = (a*function(b)-b*function(a))/(function(b)-function(a));
        cout << setprecision(10) << setw(2) << right << n << setw(20) << right << a << setw(20) << right << b << setw(20) << right << p0;
        if(function(a)*function(p0) > 0){
            a = p0;
        }
        else if (function(b)*function(p0) > 0){
            b = p0;
        }
        else{
            exit(1);
        }
        p1 = (a*function(b)-b*function(a))/(function(b)-function(a));
        cout << setprecision(10) << setw(20) << right << abs(p1-p0) << setw(20) << right << function(p0) << endl;
        n++;
    }while(abs(p1-p0) >= tolerance);
    return 0;
}