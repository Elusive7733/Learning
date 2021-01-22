#include <iostream>

using namespace std;

template <typename T>
void SelectionSort(T data[], int size)
{
	T temp;
	int minindex = 0;
	for(int i = 0; i < size; i++)
	{
		minindex = i;
		for(int j = i+1; j < size; j++)
		{
			if(data[j] < data[minindex]){
			minindex = j;
			}
		}
		if(i != minindex){
			temp = data[i];
			data[i] = data[minindex];
			data[minindex] = temp;
		}
	}
}


template <typename T>
void printarray(T data[], int size){
	for(int i = 0; i < size; i++)
	{
		cout << data[i] << " ";
	}
}

int main()
{
	int array[] = {10,2,5,3,1,4,9,8,7,6};
	char arr[] = {'a','v','c','d','e','i','k','f','z','y'};
	string names[] = {"Abdullah Raheel", "Abdullah Qaheel", "Saitama", "Dante", "Vergil", "Bruce wayne", "Flash", "Nigga", "Abdullah Saheel", "Tony Stark"};
	
	
	//for int
	cout << "Unsorted Array\n";
	printarray(array, 10);
	SelectionSort(array, 10);
	cout << endl;
	cout << endl;
	cout << "Sorted Array\n";
	printarray(array, 10); 
	cout << endl;
	cout << endl;
	
	//for char
	cout << "Unsorted Array\n";
	printarray(arr, 10);
	SelectionSort(arr, 10);
	cout << endl;
	cout << endl;
	cout << "Sorted Array\n";
	printarray(arr, 10);
	
	cout << endl;
	cout << endl;
	
	//for string
	cout << "Unsorted Array\n";
	printarray(names, 10);
	SelectionSort(names, 10);
	cout << endl;
	cout << endl;
	cout << "Sorted Array\n";
	printarray(names, 10);
	
	return 0;
}
