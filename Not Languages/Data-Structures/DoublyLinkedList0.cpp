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

	void copy_list(const list &original){
 		this->head=NULL;
		this->tail=NULL;
	 	node *ptr=original.head;
	 	while(ptr!=NULL){
			this->increment_tail(ptr->data);
		 	ptr=ptr->next;
		}
 	}

	 list(const list &original){
		 copy_list(original);
	}

	 list& operator=(const list &original){
		if(this!=&original){
			this->~list();
			copy_list(original);
		}

	}

	void increment_head(int data = 0){
		if(head != NULL){
			head = new node(data, head, NULL);
			head->next->prev = head;
		}
		else{
			head=tail=new node(data);
		}

	}

	void increment_tail(int data = 0){
		if(tail != NULL){
			tail = new node(data, NULL, tail);
			tail->prev->next = tail;
		}
		else{
			head=tail=new node(data);
		}
	}

	void display(){
		if(head!=NULL)
		{
			int node_no = 0;
			node *ptr;
			ptr=head;
			while(ptr!=NULL){
				 cout<<"Node "<<node_no<<": "<<ptr->data<<endl;
			 	ptr=ptr->next;
			 	node_no++;
			}
		}
		else{
			cout << "list is empty!" << endl;
		}
 	}

 	void delete_head(){
 		if(head!=NULL){
 			if(head == tail){
 				head = tail = NULL;
			 }
			 else{
			 	head = head->next;
			 	delete head->prev;
			 	head->prev = NULL;

			 }
		 }
		 else{
		 	cout << "The list is empty" << endl;
		 }
	 }

 	void delete_tail(){
 		if (head == tail){
		 delete head;
		 head = tail =NULL;
		 }
		 else{
			 tail = tail->prev;
			 delete tail->next;
			 tail->next=NULL;
		 }
	 }

	void searching(int data){
		int node_no = 0;
		node *ptr = head;
		bool flag = false;
		while(ptr!=NULL){
			if(ptr->data == data){
				cout<<"Data: "<<ptr->data<<" at node: "<<node_no<<endl<<endl;
				flag = true;
			}
			else if(ptr == tail && flag == false){
				cout<<"Error 404-Data doesn't exist"<<endl<<endl;
			}
			ptr=ptr->next;
			node_no++;
		}
	}

 	void reversing(){
		 node *temp = NULL;
		 node *current = head;

		 while (current != NULL){
			 temp = current->prev;
			 current->prev = current->next;
			 current->next = temp;
			 current = current->prev;
		 }

		 if(temp != NULL){
			head = temp->prev;
		 }
	}

	void add_in_between(int data = 0, int pos = 0){
		int node_no = 0;
		node *ptr = head;
		if(head==tail){
 			head=tail=new node(data,NULL,NULL);
		}
	 	else{
	 		while(node_no != pos && ptr != tail){
	 			ptr = ptr->next;
				node_no++;
			 }
			if(ptr == head){
			 	increment_head(data);
			 }
			 else if(ptr == tail){
			 	increment_tail(data);
			 }
			 else{
				ptr=new node(data,ptr,ptr->prev);
			 	ptr->prev->next=ptr;
			 	ptr->next->prev=ptr;
			 }
		}
	}

	void delete_from_between(int pos = 0){
		int node_no = 0;
		node *ptr = head;
		if(head==tail){
			cout<<"list doesn't exist"<<endl;
		}
	 	else{
	 		while(node_no != pos && ptr != tail){
	 			ptr = ptr->next;
				node_no++;
			 }
			 if(ptr == tail){
			 	delete_tail();
			 }
			 else if(ptr == head){
			 	delete_head();
			 }
			 else{
				ptr->prev->next=ptr->next;
				ptr->next->prev=ptr->prev;
				delete ptr;
			 }

		}
	}

	void circularize_the_list(){
		tail->next = head;
		head->prev = tail;
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

	int opt, opt2, element, pos;
	list list1, list2;

	do{
		system("cls");
		cout<<"1-Manage List"<<endl;
		cout<<"2-Display List"<<endl;
		cout<<"3-Search List"<<endl;
		cout<<"4-Exit program"<<endl;
		cin>>opt;
		switch(opt){
			case 1:
				system("cls");
				cout<<"1-Add an element"<<endl;
				cout<<"2-Delete an element"<<endl;
				cout<<"3-Copy the list"<<endl;
				cin>>opt2;
				if(opt2 == 1){
					system("cls");
					cout<<"1-Add to head of the list"<<endl;
					cout<<"2-Add to tail of the list"<<endl;
					cout<<"3-Add in between"<<endl;
					cin>>opt2;
					if(opt2 == 1){
						cout <<"Enter data: ";
						cin>>element;
						list1.increment_head(element);
					}
					else if(opt2 == 2){
						cout <<"Enter data: ";
						cin>>element;
						list1.increment_tail(element);
					}
					else if(opt2 = 3){
						cout <<"Enter data: ";
						cin>>element;
						cout <<"Enter position: ";
						cin>>pos;
						list1.add_in_between(element, pos);
					}
					else{
						cout<<"Invalid option."<< endl;
					}
				}

				else if(opt2 == 2){
					system("cls");
					cout<<"1-Delete head of the list"<<endl;
					cout<<"2-Delete tail of the list"<<endl;
					cout<<"3-Delete from between"<<endl;
					cin>>opt2;
					if(opt2 == 1){
						list1.delete_head();
					}
					else if(opt2 == 2){
						list1.delete_tail();
					}
					else if(opt2 = 3){
						cout <<"Enter position: ";
						cin>>pos;
						list1.delete_from_between(pos);
					}
					else{
						cout<<"Invalid option."<< endl;
					}
				}

				else if(opt2 == 3){
					system("cls");
					list2.copy_list(list1);
				}
				else{
					cout<<"Invalid option."<< endl;
				}
				break;
			case 2:
				system("cls");
				list1.display();
				getch();
				break;
			case 3:
				system("cls");
				cout<<"Enter data to search: ";
				cin>>element;
				list1.searching(element);
				getch();
				break;
			case 4: exit(1);
			default: cout<<"Invalid option."<< endl;
		}
	}while(opt != 4);
	return 0;
}

/*
bool searching(int a){
	 node *tmp;
	 for(tmp=head;tmp!=0 && tmp->data!=a;tmp=tmp->next);
	 return tmp!=0;
 }
*/
