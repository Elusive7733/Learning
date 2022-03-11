#include <iostream>
#include <cstring>

using namespace std;


void reverse(string str, int pos){
	if(pos == 0){
		cout << str[0];
		return;
	}
	cout << str[pos];
	reverse(str, pos-1);
}

int main(){
	string str;
	cout << "Enter string: ";
	cin >> str;
	reverse(str, (str.length()-1));
	return 0;
}
