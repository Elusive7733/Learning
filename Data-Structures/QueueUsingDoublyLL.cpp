#include <iostream> 
#include <cstdlib> 
#include <string.h>
#include <conio.h>

using namespace std; 

class node{
	
public:
	int data;
	node *prev, *next;

	node(int data = 0, node *next = NULL, node *prev = NULL){
		this->data = data;
		this->next = next;
		this->prev = prev;
	}
};

class list{
	
	private:
		node *head, *tail;
	
	public:
		
	list(){
		head = NULL;
		tail = NULL;
	}
	
	increment_head(int data = 0){
		if(head != NULL){
			head = new node(data, head, NULL);
			head->next->prev = head;
		}
		else{
			head=tail=new node(data);
		}
	}
	
	void display(){
		if(head!=NULL)
		{
			int Element_no = 0;
			node *ptr;
			ptr=head; 
			while(ptr!=NULL){ 
				 cout<<"Element "<<Element_no<<": "<<ptr->data<<endl; 
			 	ptr=ptr->next; 
			 	Element_no++;
			}	
		}
		else{
			cout << "The Queue is empty!" << endl;
		}
 	}
	
  	int delete_tail(){
		int element;
		if(tail!=NULL){
			if(head == tail){
				element = head->data;
				head = tail = NULL;
			 }
			 else{
			 	element = tail->data;
			 	tail = tail->prev;
			 	delete tail->next;
			 	tail->next = NULL;
			 }
			 return element;
		 }
		 else{
		 	cout << "The Queue is empty!" << endl;
		 }
	 }
 		
	 ~list(){ //destructor 
 		node *ptr; 
	 while(head!=NULL){ 
		 ptr=head->next; 
		 delete head; 
		 head=ptr; 
	 } 
 	}
};

int main()
{
	
	int opt, element; 
	list list1;
	
	do{
		system("cls");
		cout<<"1-Queue"<<endl;
		cout<<"2-Dequeue"<<endl;
		cout<<"3-Display"<<endl;
		cout<<"4-Exit program"<<endl;
		cin>>opt;
		switch(opt){
			case 1:
				system("cls");
				cout << "Enter element to add to Queue: ";
				cin >> element;
				list1.increment_head(element);
				break;
			case 2:
				system("cls");
				cout << "Element Dequeued: " << list1.delete_tail()<<endl;
				getch();
				break;
			case 3:
				system("cls");
				list1.display();
				getch();
				break;
			case 4: exit(1);
			default: system("cls"); cout<<"Invalid option."<< endl; getch();
		}	
	}while(opt != 4);
	return 0;
}

