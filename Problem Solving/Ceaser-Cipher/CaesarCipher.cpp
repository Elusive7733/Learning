#include <iostream>
#include <string>
#include <math.h>
#include <cstdlib>
#include <cmath> 
using namespace std;

class CaesarCipher
{
private:
  string str;
  int keyshift, key, base, caps;

public:
  void setkeyshift(int x)
  {
    keyshift = x;
  }
  void setkey(int x)
  {
    key = x;
  }
  void setbase(int x)
  {
    base = x;
  }
  void setcaps(int x)
  {
    caps = x;
  }
  void setstr(char x, int j)
  {
    str[j] = x;
  }
  void setstrwhole(string x)
  {
    str = x;
  }
  int getkeyshift()
  {
    return keyshift;
  }
  int getkey()
  {
    return key;
  }
  int getbase()
  {
    return base;
  }
  int getcaps()
  {
    return caps;
  }
  string getstr()
  {
    return str;
  }

   CaesarCipher(int keyshift, int key, int base, int caps, string str)
   {
     setkeyshift(keyshift);
     setkey(key);
     setbase(base);
     setcaps(caps);
     setstrwhole(str);
   }

};
//Example 1: "Abdullah Raheel" -> "Efhyppel Veliip" at Keyshift = 4
//Example 2: "ABCDEFGHIJKLMNOPQRSTUVWXYZ abcdefghijklmnopqrstuvwxyz AA Ab BB Bc CC Cd"
// -> "JKLMNOPQRSTUVWXYZABCDEFGHI jklmnopqrstuvwxyzabcdefghi JJ Jk KK Kl LL Lm" at Keyshift = 9

// Formulae:
// Base = 'X' - 65 OR 97; "Where 'X' is the alphabet" (-65 for capital Letters) (-97 for small letters)
//"Base determines which alphabet it is as each alphabet gets a unique no 'A = 0, B = 1....'"
// Key = (Base + Keyshift) %26 ; "This Assigns a unique value after shift"

//Todo:
// learn more about this formula: Key = (Base + Keyshift) %26
// add filing to this
// add decryption (without keyshift). Use frequency analysis

string encryption(){
  int tempint;
  char tempchar;
  string tempstr;
  CaesarCipher obj(0, 0, 0, 0, "AAAAA");
  cout << "Enter key-shift: ";
  cin >> tempint;
  while(tempint <= 0 || tempint > 25){
    cout << "Enter key-shift again, between (1-25): ";
    cin >> tempint;
  }
  obj.setkeyshift(tempint);
  cout << "Enter a string to encode in Caesar Cipher\n";
  fflush(stdin);
  getline(cin, tempstr);
  obj.setstrwhole(tempstr);

  for(int j = 0; j < (obj.getstr()).size(); j++){
    obj.setcaps(0);
      if((obj.getstr())[j] >= 65 && (obj.getstr())[j] <= 90){
          obj.setbase((obj.getstr())[j] - 65);
          obj.setkey((obj.getbase() + obj.getkeyshift()) % 26);
          obj.setcaps(1);
      }
      else if((obj.getstr())[j] >= 97 && (obj.getstr())[j] <= 122){
        obj.setbase((obj.getstr())[j] - 97);
        obj.setkey((obj.getbase() + obj.getkeyshift()) % 26);
      }
      else
      {
        continue;
      }

      if(obj.getcaps() == 1){
        switch (obj.getkey()){
          case 0 :
            obj.setstr('A', j);
            break;
          case 1 :
            obj.setstr('B', j);
            break;
          case 2 :
            obj.setstr('C', j);
            break;
          case 3 :
            obj.setstr('D', j);
            break;
          case 4 :
            obj.setstr('E', j);
            break;
          case 5 :
            obj.setstr('F', j);
            break;
          case 6 :
            obj.setstr('G', j);
            break;
          case 7 :
            obj.setstr('H', j);
            break;
          case 8 :
            obj.setstr('I', j);
            break;
          case 9 :
            obj.setstr('J', j);
            break;
          case 10 :
            obj.setstr('K', j);
            break;
          case 11 :
            obj.setstr('L', j);
            break;
          case 12 :
            obj.setstr('M', j);
            break;
          case 13 :
            obj.setstr('N', j);
            break;
          case 14 :
            obj.setstr('O', j);
            break;
          case 15 :
            obj.setstr('P', j);
            break;
          case 16 :
            obj.setstr('Q', j);
            break;
          case 17 :
            obj.setstr('R', j);
            break;
          case 18 :
            obj.setstr('S', j);
            break;
          case 19 :
            obj.setstr('T', j);
            break;
          case 20 :
            obj.setstr('U', j);
            break;
          case 21 :
            obj.setstr('V', j);
            break;
          case 22 :
            obj.setstr('W', j);
            break;
          case 23 :
            obj.setstr('X', j);
            break;
          case 24 :
            obj.setstr('Y', j);
            break;
          case 25 :
            obj.setstr('Z', j);
            break;
          }
      }
      else
      {
        switch (obj.getkey()) {
          case 0 :
            obj.setstr('a', j);
            break;
          case 1 :
            obj.setstr('b', j);
            break;
          case 2 :
            obj.setstr('c', j);
            break;
          case 3 :
            obj.setstr('d', j);
            break;
          case 4 :
            obj.setstr('e', j);
            break;
          case 5 :
            obj.setstr('f', j);
            break;
          case 6 :
            obj.setstr('g', j);
            break;
          case 7 :
            obj.setstr('h', j);
            break;
          case 8 :
            obj.setstr('i', j);
            break;
          case 9 :
            obj.setstr('j', j);
            break;
          case 10 :
            obj.setstr('k', j);
            break;
          case 11 :
            obj.setstr('l', j);
            break;
          case 12 :
            obj.setstr('m', j);
            break;
          case 13 :
            obj.setstr('n', j);
            break;
          case 14 :
            obj.setstr('o', j);
            break;
          case 15 :
            obj.setstr('p', j);
            break;
          case 16 :
            obj.setstr('q', j);
            break;
          case 17 :
            obj.setstr('r', j);
            break;
          case 18 :
            obj.setstr('s', j);
            break;
          case 19 :
            obj.setstr('t', j);
            break;
          case 20 :
            obj.setstr('u', j);
            break;
          case 21 :
            obj.setstr('v', j);
            break;
          case 22 :
            obj.setstr('w', j);
            break;
          case 23 :
            obj.setstr('x', j);
            break;
          case 24 :
            obj.setstr('y', j);
            break;
          case 25 :
            obj.setstr('z', j);
            break;
          }
      }
  }
  return obj.getstr();
}
string decryption(){
  int tempint;
  char tempchar;
  string tempstr;
  CaesarCipher obj(0, 0, 0, 0, "AAAAA");
  cout << "Do you know the keyshift[Y/N]: ";
  cin >> tempchar;
  while(tempchar != 'Y' && tempchar != 'y' && tempchar != 'N' && tempchar != 'n')
  {
    cout << "Invaid Option!.\nPlease enter [Y/N]: ";
    cin >> tempchar;
  }
  if(tempchar == 'Y' || tempchar == 'y')
  {
    cout << "Enter key-shift: ";
    cin >> tempint;
    while(tempint <= 0 || tempint > 25){
      cout << "Enter key-shift again, between (1-25): ";
      cin >> tempint;
    }
    obj.setkeyshift(tempint);
    cout << "Enter a string to decrypt\n";
    fflush(stdin);
    getline(cin, tempstr);
    obj.setstrwhole(tempstr);
//Revise the formulae
// not working for large Keyshifts
    for(int j = 0; j < (obj.getstr()).size(); j++){
      obj.setcaps(0);
        if((obj.getstr())[j] >= 65 && (obj.getstr())[j] <= 90){
            obj.setbase((obj.getstr())[j] - 65);
            obj.setkey(abs((obj.getbase() - obj.getkeyshift())) % 26);
            obj.setkey(26 - obj.getkey()); //(this corrects the other half)
            obj.setcaps(1);
        }
        else if((obj.getstr())[j] >= 97 && (obj.getstr())[j] <= 122){
          obj.setbase((obj.getstr())[j] - 97);
          obj.setkey(abs(obj.getbase() - obj.getkeyshift()) % 26);
          obj.setkey(26 - obj.getkey()); //(this corrects the other half)
        }
        else{
          continue;
        }

        if(obj.getcaps() == 1)
        {
          switch (obj.getkey()) {
            case 0 :
              obj.setstr('A', j);
              break;
            case 1 :
              obj.setstr('B', j);
              break;
            case 2 :
              obj.setstr('C', j);
              break;
            case 3 :
              obj.setstr('D', j);
              break;
            case 4 :
              obj.setstr('E', j);
              break;
            case 5 :
              obj.setstr('F', j);
              break;
            case 6 :
              obj.setstr('G', j);
              break;
            case 7 :
              obj.setstr('H', j);
              break;
            case 8 :
              obj.setstr('I', j);
              break;
            case 9 :
              obj.setstr('J', j);
              break;
            case 10 :
              obj.setstr('K', j);
              break;
            case 11 :
              obj.setstr('L', j);
              break;
            case 12 :
              obj.setstr('M', j);
              break;
            case 13 :
              obj.setstr('N', j);
              break;
            case 14 :
              obj.setstr('O', j);
              break;
            case 15 :
              obj.setstr('P', j);
              break;
            case 16 :
              obj.setstr('Q', j);
              break;
            case 17 :
              obj.setstr('R', j);
              break;
            case 18 :
              obj.setstr('S', j);
              break;
            case 19 :
              obj.setstr('T', j);
              break;
            case 20 :
              obj.setstr('U', j);
              break;
            case 21 :
              obj.setstr('V', j);
              break;
            case 22 :
              obj.setstr('W', j);
              break;
            case 23 :
              obj.setstr('X', j);
              break;
            case 24 :
              obj.setstr('Y', j);
              break;
            case 25 :
              obj.setstr('Z', j);
              break;
            }
        }
        else
        {
          switch (obj.getkey()) {
            case 0 :
              obj.setstr('a', j);
              break;
            case 1 :
              obj.setstr('b', j);
              break;
            case 2 :
              obj.setstr('c', j);
              break;
            case 3 :
              obj.setstr('d', j);
              break;
            case 4 :
              obj.setstr('e', j);
              break;
            case 5 :
              obj.setstr('f', j);
              break;
            case 6 :
              obj.setstr('g', j);
              break;
            case 7 :
              obj.setstr('h', j);
              break;
            case 8 :
              obj.setstr('i', j);
              break;
            case 9 :
              obj.setstr('j', j);
              break;
            case 10 :
              obj.setstr('k', j);
              break;
            case 11 :
              obj.setstr('l', j);
              break;
            case 12 :
              obj.setstr('m', j);
              break;
            case 13 :
              obj.setstr('n', j);
              break;
            case 14 :
              obj.setstr('o', j);
              break;
            case 15 :
              obj.setstr('p', j);
              break;
            case 16 :
              obj.setstr('q', j);
              break;
            case 17 :
              obj.setstr('r', j);
              break;
            case 18 :
              obj.setstr('s', j);
              break;
            case 19 :
              obj.setstr('t', j);
              break;
            case 20 :
              obj.setstr('u', j);
              break;
            case 21 :
              obj.setstr('v', j);
              break;
            case 22 :
              obj.setstr('w', j);
              break;
            case 23 :
              obj.setstr('x', j);
              break;
            case 24 :
              obj.setstr('y', j);
              break;
            case 25 :
              obj.setstr('z', j);
              break;
            }
        }
    }
  }
  return obj.getstr();
}

int main(){
  int opt;
  cout <<"1 - Encryption." << endl;
  cout <<"2 - Decryption." << endl;
  cin >> opt;

  //__________________________ENCRYPTION________________________________________
  if(opt == 1){
    cout << encryption() << endl;
  }

  //__________________________DECRYPTION________________________________________
  else if(opt == 2){
    cout << decryption() << endl;
  }
}
