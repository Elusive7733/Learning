#include <iostream>

using namespace std;



void countsort(int arr[], int size){
	int count[50] = {0};
	int output[size] = {0};
	
	for(int i = 0; i < size; i++){
		count[arr[i]]++;
	}
	for(int i = 1; i < 43; i++){
		count[i] += count[i-1];
	}
	for(int i = 0; i < size; i++){
		output[count[arr[i]]-1] = arr[i];
		count[arr[i]]--;
	}
	for(int i = 0; i < size; i++){
		arr[i] = output[i];
	}
}

void printarray(int arr[], int size){
	for(int i = 0; i < size; i++){
		cout << arr[i] << " ";
	}
}

int main(){
	
	int arr[] = {5, 6, 8, 9, 2, 4, 3, 42, 1, 0};
	cout << "Original Array: " << endl;
	printarray(arr, 10);
	cout << endl;	
	cout << "Sorted Array: " << endl;
	countsort(arr, 10);
	printarray(arr, 10);
	return 0;
}
