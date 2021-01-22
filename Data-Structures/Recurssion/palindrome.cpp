#include <iostream>
#include <cstring>

using namespace std;

int palindrome(string str, int pos, int i, int check){
	cout<<pos<< " " << i<<endl;
	cout<<check<<endl;
	system("pause");
    if(pos == -1){
    	cout << check << endl;
        return check;
    }
    if(str[i] != str[pos]){
        check = 0;
	}
    palindrome(str, pos-1, i+1, check);
}

int main(){
    string str;
    cout << "str: ";
    getline(cin, str);
    int check = 1;
//	cout << palindrome(str, str.length()-1, 0, check) << endl;
//	cout << check << endl;
	check = palindrome(str, str.length()-1, 0, check);
    if(check == 0){
        cout << "Not a palindrome";
    }
    else{
        cout << "Its a palindrome";
    }
}
