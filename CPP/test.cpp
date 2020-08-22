// #include <iostream>
// #include <exception>
// using namespace std;
//
// struct MyException : public exception {
//    const char * what () const throw () { // ye constant throw ko kata do koi farq nehi parh raha tou is bc ka kiya faida hy
//       return "fuck off mate";
//    }
//    int integerdisplay(){
//      return 99;
//    }
//    double doubledisplay(){
//      return 69.69;
//    }
// };
//
// int main() {
//    try {
//       throw MyException();
//       // throw exception();
//
//
//    }
//    catch(MyException& e) {
//       std::cout << "MyException caught" << std::endl;
//       std::cout << e.what() << std::endl;
//       std::cout << e.integerdisplay() << std::endl;
//       std::cout << e.doubledisplay() << std::endl;
//    }
//    catch(exception& e) {
//       std::cout << "Other Errors" << std::endl;
//       std::cout << e.what() << std::endl;
//    }
//
// }
//
// #include <iostream>
// #include "test.h"
// class A{
//   int a;
// public:
//   A(int x):a(x){}
// int geta(){
//     return a;
//   }
// };
// class B: private A{
//   int b;
// public:
// B(int x, int y):A(x), b(y){}
// int getb(){
//     return b;
//   }
// };
// int main() {
//
//       B obj(5, 10);
//       cout << "b: " << obj.getb() << endl;
//       cout << "a: " << obj.geta() << endl;
//
//     // int a[5] = {10, 50, 30, 40, 20};
//     // int n = sizeof(a) / sizeof(a[0]);
//     //
//     // // calls template function
//     // bubbleSort(a, 5);
//     // cout << " Sorted array : ";
//     // for (int i = 0; i < n; i++)
//     //     cout << a[i] << " ";
//     // cout << endl;
//     // reverse(a, 5);
//     // cout << " Reverse array : ";
//     // for (int i = 0; i < n; i++)
//     //     cout << a[i] << " ";
//     // cout << endl;
//
//
//   return 0;
// }


#include <iostream>

using namespace std;

class base{
public:
  void bfunc(){
    cout << "In base class" << endl;
  }
};

class derived : public base{
public:
  void dfunc(){
    cout << "In derived class" << endl;
  }
};

int main()
{
  base  *bptr, bobj;
  derived *dptr, dobj;
  dptr = (base*)(&dobj);
  bptr->bfunc();
  dptr->dfunc();
  // dptr = &bobj;
  return 0;
}
