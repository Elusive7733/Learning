#include <iostream>

using namespace std;

class circular_queue{
	public:
	
	int *storage;
	int front;
	int rear;
	int size;
	
	circular_queue(int _size = 5){
		size = _size;
		front = rear = 0;
		storage = new int [size];
	}
	
	bool is_empty(){
		if(front == rear){
			return true;
		}
		return false;
	}
	bool is_full(){
		if(front == (rear+1)%size){
			return true;
		}
		return false;
	}
	void enqueue(int data = 0){
		if(!is_full()){
			storage[rear] = data;
			rear = (rear+1)%size;
		}
		else{
			cout << "Queue Full!\n";
		}
	}
	
	void dequeue(){
		if(!is_empty()){
			cout << storage[front] << " Dequeued\n";
			storage[front] = 0;
			front = (front+1)%size;
		}
		else{
			cout << "Queue Empty!\n";
		}
	}
	
	void peek(){
		if(!is_empty()){
			cout << storage[front] << " at Front\n";
		}
		else{
			cout << "Queue Empty!\n";
		}
	}
	void display(){
		for(int i = 0; i < size; i++){
			cout << storage[i] << endl;
		}
	}
};

int main(){
	circular_queue q(5);
	int num = 0, opt = 0;
	while(opt != -1){
		fflush(stdin);
		system("cls");
		cout << "1-Enqueue\n";
		cout << "2-Dequeue\n";
		cout << "3-Display\n";
		cout << "4-Front\n";
		cout << "5-Rear\n";
		cout << "-1-Exit\n";
		cin >> opt;
		switch (opt){
		case 1:
			system("cls");
			cout << "Enter number to enqueue: ";
			cin >> num;
			q.enqueue(num);
			break;
		case 2:
			system("cls");
			q.dequeue();
			break;

		case 3:
			system("cls");
			q.display();
			break;
		case 4:
			cout << "Front: " << q.front << endl;
			break;
		case 5:
			cout << "Rear: " << q.rear << endl;
			break;
		case -1:
			break;
		default:
			system("cls");
			cout << "Error-Invalid Option\n";
			break;
		}
		system("pause");
	}
	return 0;
}
