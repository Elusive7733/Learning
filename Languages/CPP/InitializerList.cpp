#include <iostream>

using namespace std;

template<typename T>
void printList(std::initializer_list<T> greet)
{
    for (const auto &value: greet)
        cout << value << endl;
}

// Driver program
int main()
{
    // Initialization list
    printList( {"Hi", "Hey", "Hello"} );
    return 0;
}
