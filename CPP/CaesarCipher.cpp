#include <iostream>
#include <string>
#include <math.h>
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

int main()
{
    int tempint, opt;
    char tempchar;
    string tempstr;

    cout <<"1 - Encryption." << endl;
    cout <<"2 - Decryption." << endl;
    cin >> opt;

  //__________________________ENCRYPTION________________________________________
    if(opt == 1)
    {
      CaesarCipher encryption(0, 0, 0, 0, "AAAAA");

      cout << "Enter key-shift: ";
      cin >> tempint;
      while(tempint <= 0 || tempint > 25){
        cout << "Enter key-shift again, between (1-25): ";
        cin >> tempint;
      }
      encryption.setkeyshift(tempint);
      cout << "Enter a string to encode in Caesar Cipher\n";
      fflush(stdin);
      getline(cin, tempstr);
      encryption.setstrwhole(tempstr);

      for(int j = 0; j < (encryption.getstr()).size(); j++){
        encryption.setcaps(0);
          if((encryption.getstr())[j] >= 65 && (encryption.getstr())[j] <= 90){
              encryption.setbase((encryption.getstr())[j] - 65);
              encryption.setkey((encryption.getbase() + encryption.getkeyshift()) % 26);
              encryption.setcaps(1);
          }
          else if((encryption.getstr())[j] >= 97 && (encryption.getstr())[j] <= 122){
            encryption.setbase((encryption.getstr())[j] - 97);
            encryption.setkey((encryption.getbase() + encryption.getkeyshift()) % 26);
          }
          else
          {
            continue;
          }

          if(encryption.getcaps() == 1)
          {
            switch (encryption.getkey()) {
              case 0 :
                encryption.setstr('A', j);
                break;
              case 1 :
                encryption.setstr('B', j);
                break;
              case 2 :
                encryption.setstr('C', j);
                break;
              case 3 :
                encryption.setstr('D', j);
                break;
              case 4 :
                encryption.setstr('E', j);
                break;
              case 5 :
                encryption.setstr('F', j);
                break;
              case 6 :
                encryption.setstr('G', j);
                break;
              case 7 :
                encryption.setstr('H', j);
                break;
              case 8 :
                encryption.setstr('I', j);
                break;
              case 9 :
                encryption.setstr('J', j);
                break;
              case 10 :
                encryption.setstr('K', j);
                break;
              case 11 :
                encryption.setstr('L', j);
                break;
              case 12 :
                encryption.setstr('M', j);
                break;
              case 13 :
                encryption.setstr('N', j);
                break;
              case 14 :
                encryption.setstr('O', j);
                break;
              case 15 :
                encryption.setstr('P', j);
                break;
              case 16 :
                encryption.setstr('Q', j);
                break;
              case 17 :
                encryption.setstr('R', j);
                break;
              case 18 :
                encryption.setstr('S', j);
                break;
              case 19 :
                encryption.setstr('T', j);
                break;
              case 20 :
                encryption.setstr('U', j);
                break;
              case 21 :
                encryption.setstr('V', j);
                break;
              case 22 :
                encryption.setstr('W', j);
                break;
              case 23 :
                encryption.setstr('X', j);
                break;
              case 24 :
                encryption.setstr('Y', j);
                break;
              case 25 :
                encryption.setstr('Z', j);
                break;
              }
          }
          else
          {
            switch (encryption.getkey()) {
              case 0 :
                encryption.setstr('a', j);
                break;
              case 1 :
                encryption.setstr('b', j);
                break;
              case 2 :
                encryption.setstr('c', j);
                break;
              case 3 :
                encryption.setstr('d', j);
                break;
              case 4 :
                encryption.setstr('e', j);
                break;
              case 5 :
                encryption.setstr('f', j);
                break;
              case 6 :
                encryption.setstr('g', j);
                break;
              case 7 :
                encryption.setstr('h', j);
                break;
              case 8 :
                encryption.setstr('i', j);
                break;
              case 9 :
                encryption.setstr('j', j);
                break;
              case 10 :
                encryption.setstr('k', j);
                break;
              case 11 :
                encryption.setstr('l', j);
                break;
              case 12 :
                encryption.setstr('m', j);
                break;
              case 13 :
                encryption.setstr('n', j);
                break;
              case 14 :
                encryption.setstr('o', j);
                break;
              case 15 :
                encryption.setstr('p', j);
                break;
              case 16 :
                encryption.setstr('q', j);
                break;
              case 17 :
                encryption.setstr('r', j);
                break;
              case 18 :
                encryption.setstr('s', j);
                break;
              case 19 :
                encryption.setstr('t', j);
                break;
              case 20 :
                encryption.setstr('u', j);
                break;
              case 21 :
                encryption.setstr('v', j);
                break;
              case 22 :
                encryption.setstr('w', j);
                break;
              case 23 :
                encryption.setstr('x', j);
                break;
              case 24 :
                encryption.setstr('y', j);
                break;
              case 25 :
                encryption.setstr('z', j);
                break;
              }
          }
      }
      cout << encryption.getstr() << endl;
    }

  //__________________________DECRYPTION________________________________________
    else if(opt == 2)
    {
      CaesarCipher decryption(0, 0, 0, 0, "AAAAA");
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
        decryption.setkeyshift(tempint);
        cout << "Enter a string to decrypt\n";
        fflush(stdin);
        getline(cin, tempstr);
        decryption.setstrwhole(tempstr);
//Revise the formulae
// not working for large Keyshifts
        for(int j = 0; j < (decryption.getstr()).size(); j++){
          decryption.setcaps(0);
            if((decryption.getstr())[j] >= 65 && (decryption.getstr())[j] <= 90){
                decryption.setbase((decryption.getstr())[j] - 65);
                decryption.setkey(abs((decryption.getbase() - decryption.getkeyshift())) % 26);
                //decryption.setkey(26 - decryption.getkey()); (this corrects the other half)
                decryption.setcaps(1);
            }
            else if((decryption.getstr())[j] >= 97 && (decryption.getstr())[j] <= 122){
              decryption.setbase((decryption.getstr())[j] - 97);
              decryption.setkey(abs(decryption.getbase() - decryption.getkeyshift()) % 26);
              //decryption.setkey(26 - decryption.getkey()); (this corrects the other half)
            }
            else{
              continue;
            }

            if(decryption.getcaps() == 1)
            {
              switch (decryption.getkey()) {
                case 0 :
                  decryption.setstr('A', j);
                  break;
                case 1 :
                  decryption.setstr('B', j);
                  break;
                case 2 :
                  decryption.setstr('C', j);
                  break;
                case 3 :
                  decryption.setstr('D', j);
                  break;
                case 4 :
                  decryption.setstr('E', j);
                  break;
                case 5 :
                  decryption.setstr('F', j);
                  break;
                case 6 :
                  decryption.setstr('G', j);
                  break;
                case 7 :
                  decryption.setstr('H', j);
                  break;
                case 8 :
                  decryption.setstr('I', j);
                  break;
                case 9 :
                  decryption.setstr('J', j);
                  break;
                case 10 :
                  decryption.setstr('K', j);
                  break;
                case 11 :
                  decryption.setstr('L', j);
                  break;
                case 12 :
                  decryption.setstr('M', j);
                  break;
                case 13 :
                  decryption.setstr('N', j);
                  break;
                case 14 :
                  decryption.setstr('O', j);
                  break;
                case 15 :
                  decryption.setstr('P', j);
                  break;
                case 16 :
                  decryption.setstr('Q', j);
                  break;
                case 17 :
                  decryption.setstr('R', j);
                  break;
                case 18 :
                  decryption.setstr('S', j);
                  break;
                case 19 :
                  decryption.setstr('T', j);
                  break;
                case 20 :
                  decryption.setstr('U', j);
                  break;
                case 21 :
                  decryption.setstr('V', j);
                  break;
                case 22 :
                  decryption.setstr('W', j);
                  break;
                case 23 :
                  decryption.setstr('X', j);
                  break;
                case 24 :
                  decryption.setstr('Y', j);
                  break;
                case 25 :
                  decryption.setstr('Z', j);
                  break;
                }
            }
            else
            {
              switch (decryption.getkey()) {
                case 0 :
                  decryption.setstr('a', j);
                  break;
                case 1 :
                  decryption.setstr('b', j);
                  break;
                case 2 :
                  decryption.setstr('c', j);
                  break;
                case 3 :
                  decryption.setstr('d', j);
                  break;
                case 4 :
                  decryption.setstr('e', j);
                  break;
                case 5 :
                  decryption.setstr('f', j);
                  break;
                case 6 :
                  decryption.setstr('g', j);
                  break;
                case 7 :
                  decryption.setstr('h', j);
                  break;
                case 8 :
                  decryption.setstr('i', j);
                  break;
                case 9 :
                  decryption.setstr('j', j);
                  break;
                case 10 :
                  decryption.setstr('k', j);
                  break;
                case 11 :
                  decryption.setstr('l', j);
                  break;
                case 12 :
                  decryption.setstr('m', j);
                  break;
                case 13 :
                  decryption.setstr('n', j);
                  break;
                case 14 :
                  decryption.setstr('o', j);
                  break;
                case 15 :
                  decryption.setstr('p', j);
                  break;
                case 16 :
                  decryption.setstr('q', j);
                  break;
                case 17 :
                  decryption.setstr('r', j);
                  break;
                case 18 :
                  decryption.setstr('s', j);
                  break;
                case 19 :
                  decryption.setstr('t', j);
                  break;
                case 20 :
                  decryption.setstr('u', j);
                  break;
                case 21 :
                  decryption.setstr('v', j);
                  break;
                case 22 :
                  decryption.setstr('w', j);
                  break;
                case 23 :
                  decryption.setstr('x', j);
                  break;
                case 24 :
                  decryption.setstr('y', j);
                  break;
                case 25 :
                  decryption.setstr('z', j);
                  break;
                }
            }
        }
      cout << decryption.getstr() << endl;
      }
      // else
      // {
      //
      // }
    }
}
