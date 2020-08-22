#include <iostream>
#include <string>

using namespace std;

class myclass
{
    public:

        myclass(string z){ //this is a constructer
          // The code in myclass(){ \...This Code...\ } is executed as soon as an object is created
          setname(z);
          //constructers are used to set an initial value to the constructer
        }
        void setname(string x){
            name = x;
        }
        string getname(){
            return name;
        }
    private:
        string name;

};

int main()
{
    myclass obj("ELUSIVE"); //ClASS OBJ("asd") only works if there is a constructer
    cout << "Before Set.Name is Executed: " << obj.getname();
    obj.setname("Abdullah Raheel");
    cout << "\nAfter Set.Name is Executed: " << obj.getname();
    return 0;
    //EACH OBJECT has its own set of variables
}
