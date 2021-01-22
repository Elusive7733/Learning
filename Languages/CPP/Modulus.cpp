#include <iostream>
#include <string>
using namespace std;

// % is treated as x-(x/y)*y
//where (x/y) is calculated first and rounded down (5/2 becomes 2) so when x%y where x < y it always becomes 0 and we are left with x
int main()
{
 int base[26], keyshift[26], key;

 for(int i = 0; i < 26; i++){
   cout << "At " << i << ":";
   base[i] = i;
   keyshift[i] = i;
 }
 system("cls");

 for(int i = 0; i < 26; i++){
   for(int j = 1; j < 26; j++){
     key = (base[i] + keyshift[j]) % 26;
     cout << "Key: " << key << "\tAt Base: " << i << "\tAt Keyshift: " << j << endl;
   }
 }
}
