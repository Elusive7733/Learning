#include <iostream>
#include <math.h>
#include <iomanip>
#define tolerance 0.0000999

using namespace std;

double function(double x){
    return ((x*x*x)-(2*x*x)-5);
}

int main(){
    double a, b, p;
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
    system ("clear");
    cout << setw(2) << right << "n" << setw(20) << right << "P" << setw(20) << right << "|P(n)-P(n-1)|" << setw(20) << right << "f(p)" << endl << endl;
    do{
        p = b-((function(b)*(b-a))/(function(b)-function(a)));
        cout << setprecision(10) << setw(2) << right << n << setw(20) << right << p << setw(20) << right << abs(a-b) << setw(20) << right << function(p) << endl;
        a = b;
        b = p;
        n++;
    }while(abs(a-b) >= tolerance);
    return 0;
}