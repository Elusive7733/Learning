#include <iostream>

using namespace std;


struct student{
	float cgpa;
	int ID;
	string name;
};

void swap(student*, student*);

class Queue{
	public:
	
	student *data;
	int max_size;
	int size;
	
	student operator =(student &obj){
		student obj2;
		obj2.cgpa = obj.cgpa;
		obj2.ID = obj.ID;
		obj2.name = obj.name;
		return obj2;
	}
	void Max_heapify(int i) 
	{ 
    	int largest = i; 
    	int l = 2*i + 1; 
    	int r = 2*i + 2; 
		if (l < size && data[l].cgpa > data[largest].cgpa){
			largest = l; 
		}
		    
		if (r < size && data[l].cgpa > data[largest].cgpa){
			 largest = r; 
		} 
		if (largest != i){ 
			swap(&data[i], &data[largest]);
		    Max_heapify(largest); 
		} 
	}		
	
	void Min_heapify(int i){
		int smallest = i; 
    	int l = 2*i + 1; 
    	int r = 2*i + 2; 
		if (l < size && data[l].cgpa < data[smallest].cgpa){
			smallest = l; 
		}
		    
		if (r < size && data[r].cgpa < data[smallest].cgpa){
			 smallest = r; 
		} 
		if (smallest != i) 
		{ 
			swap(&data[i], &data[smallest]);
		    Min_heapify(smallest); 
		} 
	}
	
	Queue(int _size = 5){
		max_size = _size;
		size = 0;
		data = new student[max_size];
	}
	
	void Enqueue(string _name, int _id, float _cgpa){
		if(size == max_size){
			cout << "Queue Full\n";
		}
		else{
			fflush(stdin);
			data[size].name = _name;
			data[size].ID = _id;
			data[size].cgpa = _cgpa;
			size++;
		}
	}
	
	void Dequeue(){
		if(size == 0){
			cout << "Queue Empty\n";
		}
		else if(size == 1){
			cout << "Name: " << data[0].name << endl;
			cout << "ID: " << data[0].ID << endl;
			cout << "CGPA: " << data[0].cgpa << endl;
			size--;			
		}
		else{
			for(int i = size/2-1; i >= 0; i--){
				Min_heapify(i);
			}
			cout << "Name: " << data[0].name << endl;
			cout << "ID: " << data[0].ID << endl;
			cout << "CGPA: " << data[0].cgpa << endl;
			swap(data[0], data[size-1]);
			size--;
		}
	}
	void peek(){
		if(size == 0){
			cout << "Queue Empty\n";
		}
		else{
			cout << "Name: " << data[size-1].name << endl;
			cout << "ID: " << data[size-1].ID << endl;
			cout << "CGPA: " << data[size-1].cgpa << endl;
		}
	}
	
	void display(){
		for(int i = 0; i < size; i++){
			cout << "Name: " << data[i].name << endl;
			cout << "ID: " << data[i].ID << endl;
			cout << "CGPA: " << data[i].cgpa << endl;
			cout << endl << endl;
		}
	}

};

void swap(student *ptr1, student *ptr2){
	student temp;
	temp = *ptr1;
	*ptr1 = *ptr2;
	*ptr2 = temp;
}


int main(){
	Queue q1(5);
	q1.Enqueue("Abdullah Raheel", 170, 3.4);
	q1.Enqueue("Ammar", 1037, 3.7);
	q1.Enqueue("Mahad", 187, 3.8);
	q1.Enqueue("Ashhad", 1111, 2.9);
	q1.Enqueue("Muzaffar", 1112, 3.5);
	q1.display();
	system("cls");
	
	for (int i = 5 / 2 - 1; i >= 0; i--){
        q1.Min_heapify(i);
    }
    
    q1.display();
//	q1.Dequeue();
//	cout << endl;
//	q1.Dequeue();
//	cout << endl;
//	q1.Dequeue();
//	cout << endl;
	return 0;
}

