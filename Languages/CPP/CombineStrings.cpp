#include <iostream>
#include <string>
using namespace std;

int main()
{
    string str1, str2, str3;
    cout << "Enter String 1: ";
    getline(cin, str1);
    cout << "Enter String 2: ";
    getline(cin, str2);
    cout << "String 1: " << str1;
    cout << "\nString 2: " << str2 << endl;
    str3 = str1 + " " + str2;
    cout << "String 3: " << str3;
}
