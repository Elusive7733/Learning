#include<iostream>
using namespace std;

class Co{

public: int x, y;

  Co(int x, int y)
  {
    (*this).x = x;
    (*this).y = y;
  }
  void display()
  {
    cout<<"x: "<< x <<"\ty: "<< y << endl;
  }
};
int main()
{
  Co p1(5, 3);
  p1.display();
}
