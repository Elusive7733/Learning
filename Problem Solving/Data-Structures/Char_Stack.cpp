#include <iostream>
#include <cstring>
#include <string>

using namespace std;

class stack{
	public:
		int top;
		int size;
		char *arr;
		stack(int _size = 5){
			size = _size;
			top = 0;
			arr = new char [size];
			for(int i = 0; i < size; i++){
				arr[i] = '0';
			}
		}
		
		char pop(){
			if(top == 0){
				cout << "Stack is Empty" << endl;
				return -1;
			}
			else{
				char temp;
				temp = arr[top-1];
				top--;
				return temp;
			}
		}
		void push(char data){
			if(top == size){
				cout << "Stack is Full" << endl;
			}
			else{
				arr[top] = data;
				top++;
			}
		}
		char peek(){
			if(top == 0){
				cout << "Stack is Empty" << endl;
				return -1;
			}
			else{
				return arr[top-1];	
			}
		}
		bool is_full(){
			if(top == size){
				return true;
			}
			else{
				return false;
			}
		}
		bool is_empty(){
			if(top == 0){
				return true;
			}
			else{
				return false;
			}
		}
		
	
	void display(){
		for(int i = 0; i < size; i++){
			cout << arr[i];
		}
		cout << endl;
	}
};

void grouping_symbols(stack &stkA, string str){
	for(int i = 0; i < str.length(); i++){
		if(str[i] == '{' || str[i] == '[' || str[i] == '('){
			stkA.push(str[i]);
		}
		else{		
			switch(str[i]){
				case '}':
					if(stkA.peek() == '{'){
						stkA.pop();
					}
					break;
				case ']':
					 if(stkA.peek() == '['){
					 		stkA.pop();
						}
						break;
						
				case ')': 
					if(stkA.peek() == '('){
							stkA.pop();
						}
						break;
				default: break;
			}
		}
	}
}

int main(){
	string str;
	cout << "Enter String\n";
	getline(cin, str);
	stack stk(str.length());
	grouping_symbols(stk, str);
	if(stk.is_empty() == true){
		cout << "Contains matching grouping symbols" << endl;
	}
	else{
		cout << "Does not contains matching grouping symbols" << endl;
	}
}


