#include<iostream>
using namespace std ;

class car{

private:
    int *model;
    int *regno;

    public:
    car(int m, int r)
    {
        model= new int;
        *model=m;
        regno= new int;
        *regno=r;
    }

    car(car &c)
    {
        model= new int;
        *model=*(c.model);
        regno = new int ;
        *regno = *(c.regno);
    }
    void display()
    {
        cout << *model << " at " << model << endl ;
        cout << *regno << " at " << regno << endl ;

    }

    void set()
    {
        cout << "Enter value: " ;
        cin >> *model ;
        cout << "Enter value: " ;
        cin >> *regno ;
    }

    ~car()
    {
        delete model;
        delete regno;
    }
};

int main()
{
    car c1(10,10);
    car c2(c1);
    c1.display();
    c2.display();
    c1.set();
    c2.set();
    c1.display();
    c2.display();
    return 0;
}
