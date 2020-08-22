#include "test.h"
#include <iostream>

using namespace std;

class A{
protected:
  int x;
public:
  A(int x)
  {
    (*this).x = x;
    cout << "Constructer of Class A is called!." << endl;
  }
  int getx(){return x;}
};
class B: public A{
protected:
  int y;
public:
  B(int x, int y) : A(x)
  {
    (*this).y = y;
    cout << "Constructer of Class B is called!." << endl;
  }
  int gety(){return y;}
};

class C: public B{
protected:
  int z;
public:
  C(int x, int y, int z) : B(x, y)
  {
    (*this).z = z;
    cout << "Constructer of Class C is called!." << endl;
  }
  int getz(){return z;}
};

int main()
{
    C a(33,21,97);
    cout << "OBJECT OF CLASS C" << endl;
    cout << "X: " << a.getx() << endl;
    cout << "Y: " << a.gety() << endl;
    cout << "Z: " << a.getz() << endl;
    cout << endl;

    B a1(33,21); //,97
    cout << "OBJECT OF CLASS B" << endl;
    cout << "X: " << a1.getx() << endl;
    cout << "Y: " << a1.gety() << endl;
    //cout << "Z: " << a.getz() << endl; this is an error
    cout << endl;

    A a2(33); //,21,97
    cout << "OBJECT OF CLASS A" << endl;
    cout << "X: " << a2.getx() << endl;
    //cout << "Y: " << a1.gety() << endl; this is an error
    //cout << "Z: " << a.getz() << endl; this is an error
    cout << endl;
    return 0;
}
