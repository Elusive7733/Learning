#include <iostream>

using namespace std;

class A {
  int a , b;
public:
  A(int j = 0, int k = 0){
    b = k;
    a = j;
  }

  void display() {
    cout << "A: " << a << endl ;
    cout << "B: " << b << endl ;
  }
};

int main() {
  A k[3] = {{3, 2}, {5, 4}, {7, 6}};
  for(int i = 0; i < 3; i++){
    cout << &k[i] << " at value of i: " << i << endl;
    k[i].display();
  }
  k[0]=A();
  for(int i = 0; i < 3; i++){
    cout << &k[i] << " at value of i: " << i << endl;
    k[i].display();
  }
  return 0;
}
