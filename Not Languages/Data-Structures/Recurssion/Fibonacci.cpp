#include <iostream>
using namespace std;
void fibonacci(int prev, int next, int count, int n){
	
	if(count == n){
	 	return; 
	}
	
	cout << prev << " ";
	fibonacci(next, next+prev, count+1, n);
}
	
int main(){
	
	int N;
	cout << "Enter Stopping point for the fibonnaci sequence: ";
	cin >> N;
	fibonacci(0, 1, 0, N);
	return 0;
}
