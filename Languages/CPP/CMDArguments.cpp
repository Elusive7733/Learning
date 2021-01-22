#include <iostream>
#include <fstream>

using namespace std;

int main(int argc, char * argv[])
{
  ifstream file1;
  ofstream file2;

  string str;

  if(argc >= 3)
  {
    file1.open(argv[1]);
    file2.open(argv[2]);
    if (file1.is_open())
    {
        while(!file1.eof()){
          getline(file1,str);
          file2 << str << endl;
        }
    }
    else{
     cout << "File can not be opened" << endl;
    }
  }
  else{
     cout << "Invalid amount of arguments passed" << endl;
   }
}
