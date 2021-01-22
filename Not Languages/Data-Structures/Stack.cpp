#include <iostream>

using namespace std;

class stack{
	public:
		int top;
		int size;
		int *arr;
		stack(int _size = 5){
			size = _size;
			top = 0;
			arr = new int (size);
		}
		
		int pop(){
			if(top == 0){
				cout << "Stack is Empty" << endl;
				return -1;
			}
			else{
				int temp;
				temp = arr[top-1];
				top--;
				return temp;
			}
		}
		void push(int data){
			if(top == size){
				cout << "Stack is Full" << endl;
			}
			else{
				arr[top] = data;
				top++;
			}
		}
		int peek(){
			if(top == 0){
				cout << "Stack is Empty" << endl;
				return -1;
			}
			else{
				return arr[top];	
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
		
	void reverseStack(stack &StackB){
		int count = 0;
		while(top != 0){
			StackB.push(pop());
			count++;
		}
		top = count;
	}
	
	void display(){
		for(int i = 0; i < size; i++){
			cout << arr[i];
		}
		cout << endl;
	}
};

//void reverseStack(stack &StackA, stack &StackB){
//		int count = 0;
//		while(StackA.top != 0){
//			StackB.push(StackA.pop());
//			count++;
//		}
//		StackA.top = count;
//}

int main(){
	stack stk1(7);
	stack stk2(7);
	stk1.push(1);
	stk1.push(2);
	stk1.push(3);
	stk1.push(4);
	stk1.push(5);
	stk1.push(6);
	stk1.push(7);
	stk1.reverseStack(stk2);
	stk1.display();
	stk2.display();
}
