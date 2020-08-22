#include <iostream>

using namespace std;


class encapsulation{

private:
  void printd(){
    cout << "d" << endl;
  }
  void printc(){
    cout << "c" << endl;
    printd();
  }
  void printb(){
    cout << "b" << endl;
    printc();
  }
public:
  void printa(){
    cout << "a" << endl;
    printb();
  }
};

int main()
{
  encapsulation obj;
  obj.printa();
  return 0;
}
