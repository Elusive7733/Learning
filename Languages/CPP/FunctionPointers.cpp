#include <iostream>
#include <stdlib.h>
#include <conio.h>

using namespace std;

int Product(int x, int y)
{ return x*y; }

int sum(int x, int y)
{ return x+y; }

int subtract(int x, int y)
{ return  x-y; }

int func(int x, int y, int (*functiontocall)(int,int))
{ return ((*functiontocall)(x,y));}

int main()
{
    int a, b, opt ,temp, flag = 0;
    do{
        system("cls");
        if(flag == 0){
            cout << "Enter A and B values respectively :" << endl;
            cin >> a >> b;
        }

        cout << "\n1-Product\n2-Sum\n3-Subtract\n\nPress -1 To exit\n" << endl;
        cin >> opt;

        if(opt == 1)
        {
            temp = func(a, b, Product);
            cout << "Product : " << temp << endl ;
        }
        else if(opt == 2)
        {
            temp = func(a, b, sum);
            cout << "Sum : " << temp << endl ;
        }
        else if(opt == 3)
        {
            temp = func(a, b, subtract);
            cout << "Subtraction : " << temp << endl ;
        }

        getch();
        cout << "To you New values of A & B Enter 0" << endl;
        cin >> flag;

    }while(opt != -1);
    return 0;
}
