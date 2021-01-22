#include<iostream>
using namespace std ;
class car {

    private:

    int *model; // Pointer Declared
    int *regno; // Pointer Declared
    public:
    car(int m, int r)
    {

        model = new int; // this is where DMA is allocated
        regno = new int; // this is where DMA is allocated
        *model=m;
        *regno=r;
    }

    void display()
    {
        cout << "Memory location of object: " << this << endl ;
        cout << "Model memory stored: " << model << " Value stored: " << *model << " Location: " << &model << endl ;
        cout << "Regno memory stored: " << regno << " Value stored: " << *regno << " Location: " << &regno << endl ;

    }

    void set()
    {
        cout << "Enter model: " ;
        cin >> *model ;
        cout << "Enter regno: " ;
        cin >> *regno ;
    }

    ~car(){
        delete model;
        delete regno;
    }
};

int main()
{
    car c1(10,10);
    car c2=c1;
    c2.display();
    c1.display();
    c1.set();
    c2.display();
    c1.display();

    return 0;
}
