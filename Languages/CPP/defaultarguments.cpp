#include <iostream>

// int volume(int l, int w, int h){
//   return l*w*h;
// } this will give error

int volume(int l=10, int w=10, int h=10){
  return l*w*h;
}
int main()
{ // this is only possible using default arguments
  std::cout << volume() << std::endl;
  std::cout << volume(5) << std::endl;
  std::cout << volume(5,5) << std::endl;
  std::cout << volume(5,5,5) << std::endl;
}
