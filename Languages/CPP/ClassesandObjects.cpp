#include <iostream>
#include <string>

using namespace std;

class myclass
{
    public:

        void setname(string x){
            name = x;
        }
        string getname(){
            return name;
        }
    private:
      //Never make Variables Public
        string name;

};

int main()
{
    myclass obj;
    obj.setname("Abdullah Raheel");
    cout << obj.getname();
    return 0;
}
