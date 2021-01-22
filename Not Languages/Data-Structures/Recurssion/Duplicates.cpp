#include <iostream>

using namespace std;

int duplicates = 0;

void duplicate(int* array, int pos, int i, int size){
	if(pos == size){
		return;
	}
	if(array[pos] == array[i]){
		if(pos != i){
			duplicates++;
		}
	}
	if(i != size){
		duplicate(array, pos, i+1, size);
	}
	else{
		duplicate(array, pos+1, 0, size);
	}
}

int main(){
	int array[] = {1,1,2,2,3,3,4,4,5,9};
	duplicate(array, 0, 0, 9);
	cout << duplicates;
	return 0;
}
