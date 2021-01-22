#include <iostream>

using namespace std;


int getmax(int arr[], int size){
	int max = 0;
	for(int i = 0; i < size; i++){
		if(arr[i] > max){
			max = arr[i];
		}
	}
	return max;
}

void printarray(int arr[], int size){
	for(int i = 0; i < size; i++){
		cout << arr[i] << " ";
	}
}

void countsort(int arr[], int size, int exp){
	int count[10] = {0};
	int output[size] = {0};
	
	for(int i = 0; i < size; i++){
		count[(arr[i]/exp)%10]++;
	}
	for(int i = 1; i < 10; i++){
		count[i] += count[i-1];
	}
    for (int i = size-1; i >= 0; i--) 
    { 
        output[count[(arr[i]/exp)%10 ] - 1] = arr[i]; 
        count[(arr[i]/exp)%10 ]--; 
    } 
	for(int i = 0; i < size; i++){
		arr[i] = output[i];
	}
}

void radixsort(int arr[], int size){
	int max = getmax(arr, size);
	for(int exp = 1; max/exp > 0; exp *= 10){
		countsort(arr, size, exp);
		cout << "Pass: " << exp << endl;
		printarray(arr, size);
		cout << endl << endl;
	}	
}



int main(){
	
	int arr[] = {509, 671, 801, 9784, 214, 41, 378, 402, 100, 74};
	cout << "Original Array: " << endl;
	printarray(arr, 10);
	cout << endl << endl;
	radixsort(arr, 10);	
	cout << "Sorted Array: " << endl;
	printarray(arr, 10);
	return 0;
}
