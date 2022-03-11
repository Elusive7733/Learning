#include <iostream>

using namespace std;

template <typename T>
void insertionSort(T data[], int size)
{
	T temp;
	int j;
	for(int i = 1; i < size; i++)
	{
		temp = data[i];
		j = i-1;
		
		while((j>=0)&&(data[j]>temp))
		{
			data[j+1] = data[j];
			j = j-1;	
		}	
		data[j+1] = temp;
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
	insertionSort(array, 10);
	cout << endl;
	cout << endl;
	cout << "Sorted Array\n";
	printarray(array, 10); 
	cout << endl;
	cout << endl;
	
	//for char
	cout << "Unsorted Array\n";
	printarray(arr, 10);
	insertionSort(arr, 10);
	cout << endl;
	cout << endl;
	cout << "Sorted Array\n";
	printarray(arr, 10);
	
	cout << endl;
	cout << endl;
	
	//for string
	cout << "Unsorted Array\n";
	printarray(names, 10);
	insertionSort(names, 10);
	cout << endl;
	cout << endl;
	cout << "Sorted Array\n";
	printarray(names, 10);
	
	return 0;
}
