#include <iostream>
#include <fstream>
#include<conio.h>
using namespace std;

fstream file1, file2;

void insertrecord()
{
	int recordstoadd;
	string str;
	cout << "How many records you want to add: ";
	cin >> recordstoadd;
	file1.open("File.txt", ios::app);
	for(int i = 0; i < recordstoadd; i++)
	{
		cout << "Enter String" << endl;
		fflush(stdin);
		getline(cin, str);
		file1 << str << endl;
	}
	
	file1.close();
}

void deleterecord()
{
	int removestatus, renamestatus;
	string str;
	int i = 0;
	int index;
	file1.open("File.txt", ios::in);
	file2.open("Copy.txt", ios::out);
	
	 cout << "Enter Index at which you want to delete the record: ";
	 cin >> index;
	 
	 while(!file1.eof())
	 {
	 	fflush(stdin);
	 	getline(file1, str);
	 	if(i != index)
	 	{
	 		file2 << str << endl;
		}
	 	i++;
	 }
	 
	 file1.close();
	 file2.close();
	 removestatus = remove("File.txt");
	 renamestatus = rename("Copy.txt", "File.txt");
	if(removestatus == 0 && renamestatus == 0)
	{
		cout<<"File.txt Edited successfully" << endl;
		cout<<"Copy.txt renamed to File.txt" << endl <<endl;
	}
	else
	{
		cout<<"File not edited"<<endl;
	}

}

void editrecord(){

	int removestatus, renamestatus;
	string str;
	int i = 0;
	int index;
	file1.open("File.txt", ios::in);
	file2.open("Copy.txt", ios::out);
	
	 cout << "Enter Index at which you want to edit the record: ";
	 cin >> index;
	 
	 while(!file1.eof())
	 {
	 	fflush(stdin);
	 	getline(file1, str);
	 	if(i != index)
	 	{
	 		file2 << str << endl;
		}
		else if ( i == index){
			cout<<"Enter new information\n";
			fflush(stdin);
			getline(cin, str);
			file2 << str << endl;
			
		}
	 	i++;
	 }
	 
	 file1.close();
	 file2.close();
	 removestatus = remove("File.txt");
	renamestatus = rename("Copy.txt", "File.txt");
	if(removestatus == 0 && renamestatus == 0)
	{
		cout<<"File.txt Edited successfully" << endl;
		cout<<"Copy.txt renamed to File.txt" << endl <<endl;
	}
	else
	{
		cout<<"File not edited"<<endl;
	}

}
void display()
{
	string str;
	system("cls");
	file1.open("File.txt", ios::in);
	if(file1.is_open())
	{
		while(!file1.eof())
		{
			getline(file1, str);
			cout << str << endl;
		}
	}
	else{
		cout << "File does not exist\n";
	}
	getch();
}

int main()
{
	int choice;
	do
	{
		system("cls");
		cout << "1-Insert\n";
		cout << "2-Edit\n";
		cout << "3-Delete\n";
		cout << "4-Display\n";
		cout << "5-Terminate Program\n";
		cin >> choice;
	if ( choice == 1){
		insertrecord();
	}
	else if (choice == 2){
		editrecord();
	}
	else if (choice == 3){
		deleterecord();
	}
	else if (choice == 4){
		display();
	}
	else if (choice == 5){
		break;
	}
	else cout<<"ERROR 404\n"<<endl;
	}while(choice != 5);
	return 0;
}
